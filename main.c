/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 11:16:57 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "signal/minsignal.h"
#include "parse/parse_test.h"

static void		signal_exit(t_list *env_list);
static t_list	*main_init(int argc, char *argv[], char **envp);

int	main(int argc, char *argv[], char **envp)
{
	char	*line;
	t_tree	*tree;
	t_list	*env_list;

	env_list = main_init(argc, argv, envp);
	signalinit();
	while (1)
	{
		line = readline("minishell: ");
		if (line == NULL)
			break ;
		signal_exit(env_list);
		if (ft_strlen(line) != 0)
			add_history(line);
		tree = parse(line, env_list);
		if (!tree)
			continue ;
		if (herdoc_tree_init(tree, env_list) == 0)
			inorder_cmd_tree(tree, env_list, START);
		clear_tree(tree);
		free(line);
	}
	do_sigterm();
	exit (((t_builtin *)env_list->content)->exit_num);
}

static t_list	*main_init(int argc, char *argv[], char **envp)
{
	t_list	*env_list;

	(void)argc;
	(void)argv;
	env_list = NULL;
	env_list = parse_env(envp);
	return (env_list);
}

static void	signal_exit(t_list *env_list)
{
	if (g_signal == -1)
	{
		g_signal = 0;
		((t_builtin *)env_list->content)->exit_num = 1;
	}
}

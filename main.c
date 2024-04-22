/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/22 19:59:43 by soljeong         ###   ########.fr       */
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

static void	do_sigterm(void);

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char *argv[], char **envp)
{
	char	*line;
	t_list	*token_head;
	t_tree	*tree;
	t_list	*env_list;
	int		heredoc_count;
	int		idx = 0;

	heredoc_count = 0;
	(void)argc;
	(void)argv;
	(void)envp;
	if (*envp == NULL)
		exit(1);
	env_list = parse_env(envp);
	signalinit();
	while (idx < 1)
	{
		line = readline("minishell: ");
		if (g_signal == -1)
		{
			g_signal = 0;
			((t_builtin *)env_list->content)->exit_num = 1;
		}
		if (line == NULL)
			break ;
		if (ft_strlen(line) != 0)
			add_history(line);
		token_head = tokenizer(line);
		if (!token_head)
		{
			((t_builtin *)env_list->content)->exit_num = 258;
			free(line);
			continue ;
		}
		tree = parse_tree(&token_head);
		if (!tree)
		{
			((t_builtin *)env_list->content)->exit_num = 258;
			free(line);
			continue;
		}
		inorder_cmd_tree(tree, env_list, START, &heredoc_count);
		clear_tree(tree);
		free(line);
	}
	//exit(1);
	do_sigterm();
	return (((t_builtin *)env_list->content)->exit_num);
}

static void	do_sigterm(void)
{
	// set_terminal_print_off();
	ft_putstr_fd("\e8\e[B\e[A", 1);
	ft_putstr_fd("exit\n", 1);
}

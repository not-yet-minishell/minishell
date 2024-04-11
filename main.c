/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/11 11:35:23 by soljeong         ###   ########.fr       */
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

static void	do_sigterm(void);

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char *argv[], char **envp)
{
	char	*line;
	t_list	*head;
	t_tree	*tree;

	(void)argc;
	(void)argv;
	signalinit();
	while (1)
	{
		line = readline("minishell: ");
		if (line == NULL)
			break;
		add_history(line);
		head = tokenizer(line);
		if (!head)
		{
			free(line);
			continue ;
		}
		tree = parse_tree(&head);
		inorder_cmd_tree(tree,parse_env(envp),START);
		clear_tree(tree);
		free(line);
	}
	do_sigterm();
}

static void	do_sigterm(void)
{
	set_terminal_print_off();
	ft_putstr_fd("\033[1A", 2); // 현재 커서의 위치를 한칸 위로 올려줌
	ft_putstr_fd("\033[11C", 2); // 현재 커서의 위치를 11번째칸으로 이동
	ft_putstr_fd("exit\n", 2);
}
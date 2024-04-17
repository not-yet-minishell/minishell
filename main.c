/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2024/04/17 14:57:29 by yeoshin          ###   ########.fr       */
=======
/*   Updated: 2024/04/17 14:25:07 by yeoshin          ###   ########.fr       */
>>>>>>> Stashed changes
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

	heredoc_count = 0;
	(void)argc;
	(void)argv;
	(void)envp;
	env_list = parse_env(envp);
	signalinit();
	while (1)
	{
		line = readline("minishell: ");
		if (line == NULL)
			break ;
		add_history(line);
		token_head = tokenizer(line);
		//ft_lstiter(token_head,(void *)curr_list_print);
		if (!token_head)
		{
			free(line);
			continue ;
		}
		tree = parse_tree(&head);
		inorder_cmd_tree(tree,parse_env(envp),START);
		clear_tree(tree);
		free(line);
		//leaks();
		//while(1);
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
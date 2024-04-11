/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/11 11:03:07 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char *argv[], char **envp)
{
	char	*line;
	t_list	*head;
	t_tree	*tree;
	t_list	*env_list;

	(void)argc;
	(void)argv;
	env_list = parse_env(envp);
	while (1)
	{
		line = readline("minishell: ");
		// line nuull 체크해서 exit 코드
		// ctrl + c 눌렀을때 프로그램 안꺼지고 다음 프롬프트
		// ctrl + \ 했을때 아무 동작도 안하게! 자식프로세스는 꺼지고 , 부모프로세스는 아무동작도 안하게
		// heredoc도 조금 다르다!
		add_history(line);
		head = tokenizer(line);
		if (!head)
		{
			free(line);
			continue ;
		}
		tree = parse_tree(&head);
		//leaks();
		inorder_cmd_tree(tree, env_list, START);
		//ret = pipe(list);
		//inorder_cmd_tree(ret);
		clear_tree(tree);
		free(line);
	}
}

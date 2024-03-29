/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/28 14:23:56 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include "parse.h"

void	print_node(t_token *node)
{
	if (!node)
		return ;
	printf("str : %s\n", node->str);
	printf("token : %d\n", node->type);
}

void	leaks(void)
{
	system("leaks minishell");
}

int	main(void)
{
	char	*line;
	t_list	*head;
	t_tree	*tree;

	//atexit(leaks);
	//wait(1)
	//..????????????????????????????????????
	//..?
	while (1)
	{
		line = readline("examshell : ");
		add_history(line);
		head = tokenizer(line);
		if (!head)
		{
			printf("error\n");
		}
		// head를 return으로 받고 null이 아닐때만 실행부로 넘김
		//ft_lstiter(head, (void *)print_node);
		tree = parse_tree(&head);
		if (!tree)
			printf("error\n");
		tree_inorder_print(tree);
		// parse_tree에서 tree를 받고, null이 아닐때만 실행부로 넘김
		ft_lstclear(&head, (void *)ft_del_token_node);
		//ft_parse_tree(head)'
	}
}

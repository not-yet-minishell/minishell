/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/01 16:44:03 by soljeong         ###   ########.fr       */
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

int	main(void)
{
	char	*line;
	t_list	*head;
	t_tree	*tree;

	while (1)
	{
		line = readline("examshell : ");
		add_history(line);
		head = tokenizer(line);
		if (!head)
			printf("error\n");
		tree = parse_tree(&head);
		if (!tree)
			printf("error\n");
		tree_inorder_print(tree);
		// parse_tree에서 tree를 받고, null이 아닐때만 실행부로 넘김
		ft_lstclear(&head, (void *)ft_del_token_node);
		//ft_parse_tree(head)'
	}
}

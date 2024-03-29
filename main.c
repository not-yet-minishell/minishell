/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/28 17:16:57 by soljeong         ###   ########.fr       */
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
	printf("token : %d\n", node->token);
}

void	leaks(void)
{
	system("leaks minishell");
}

int	main(void)
{
	char	*line;
	t_list	*head;

	atexit(leaks);
	while (1)
	{
		head = ft_lstnew(NULL);
		line = readline("minishell$ ");
		add_history(line);
		head = tokenizer(line);
		if (head)
			ft_lstiter(head, (void *)print_node);
		ft_lstclear(&head, (void *)ft_del_token_node);
	}
}

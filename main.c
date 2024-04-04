/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/02 14:23:47 by soljeong         ###   ########.fr       */
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
		{
			free(line);
			continue;
		}
		tree = parse_tree(&head);
		clear_tree(tree);
		free(line);
	}
}

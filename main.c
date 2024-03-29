/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/29 18:12:18 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include "parse/parse.h"
#include "parse/parse_test.h"

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

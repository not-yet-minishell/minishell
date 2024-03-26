/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:24:51 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/26 19:34:20 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ft_exit(t_list *head)
{
	t_list	*cmd_node;
	int		exit_num;

	cmd_node = head;
	head = head->next;
	exit_num = ft_atoi(cmd_node->content);
	ft_printf(STDIN_FILENO, "%s\n", cmd_node->content);
	if (isnum(head->content) == FALSE || exit_num == FALSE)
	{
		exit_num = 255;
		error_handler(cmd_node->content, head->content, NULL);
		exit(exit_num);
	}
	if (head->next != NULL)
	{
		error_handler(cmd_node->content, NULL, NULL);
		free_list(head);
		//change_exitnumber();
	}
	else
		exit(exit_num);
}

static int	isnum(char *content)
{
	if (*content == '\0')
		return (FALSE);
	if (*content == '-' || *content == '+')
		content ++;
	while (*content)
	{
		if (*content >= '0' && *content <= '9')
			content++;
		else
			return (FALSE);
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:52:21 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 12:20:30 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_wildcard_has(t_list **curr_cmd, t_list **cmd_list, \
	t_list *prev, t_list *wild_list);

void	wildcard_cmd(t_list **cmd_list)
{
	t_list	*prev;
	t_list	*curr_cmd;
	t_list	*wild_list;

	prev = NULL;
	curr_cmd = *cmd_list;
	wild_list = NULL;
	while (curr_cmd)
	{
		if (has_wildcard(curr_cmd->content))
		{
			wild_list = find_wildcard(curr_cmd->content);
			if (wild_list != NULL)
				cmd_wildcard_has(&curr_cmd, cmd_list, prev, wild_list);
			else
				cmd_wildcard_none(&curr_cmd);
		}
		prev = curr_cmd;
		if (curr_cmd)
			curr_cmd = curr_cmd->next;
	}
}

void	cmd_wildcard_has(t_list **curr_cmd, t_list **cmd_list, \
	t_list *prev, t_list *wild_list)
{
	t_list	*temp;

	temp = *curr_cmd;
	ft_lstlast(wild_list)->next = temp->next;
	if (prev)
		prev->next = wild_list;
	else
		*cmd_list = wild_list;
	(*curr_cmd) = wild_list;
	free(temp->content);
	free(temp);
}

void	cmd_wildcard_none(t_list **curr_cmd)
{
	int		i;
	char	*str;

	i = 0;
	str = (*curr_cmd)->content;
	while (str[i])
	{
		if (str[i] == '\12')
			str[i] = '*';
		i++;
	}
}

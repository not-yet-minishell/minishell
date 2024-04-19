/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_rd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:53:56 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/19 11:21:34 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wildcard_rd(t_list **rd_list)
{
	t_list	*curr_rd;
	char	*filename;
	t_list	*file_list;

	curr_rd = *rd_list;
	while (curr_rd)
	{
		filename = ((t_rd_node *)curr_rd->content)->filename;
		file_list = find_wildcard(filename);
		if (ft_lstsize(file_list) > 1)
		{
			((t_rd_node *)curr_rd->content)->rd_type = REDIRECT_AM;
			ft_lstclear(&file_list, free);
			return ;
		}
		if (file_list != NULL)
		{
			((t_rd_node *)curr_rd->content)->filename = file_list->content;
			free(filename);
			free(file_list);
		}
		curr_rd = curr_rd->next;
	}
}

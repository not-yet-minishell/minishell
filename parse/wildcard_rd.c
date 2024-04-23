/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_rd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:53:56 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 17:38:31 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <histedit.h>
#include <dirent.h>

static void	rd_wildcard_none(t_list **curr_rd);
static void	file_list_one(char *filename, t_list **file_list, t_list **curr_rd);

void	wildcard_rd(t_list **rd_list)
{
	t_list	*curr_rd;
	char	*filename;
	t_list	*file_list;

	curr_rd = *rd_list;
	while (curr_rd)
	{
		filename = ((t_rd_node *)curr_rd->content)->filename;
		if (has_wildcard(filename))
		{
			file_list = find_wildcard(filename);
			if (ft_lstsize(file_list) > 1)
			{
				((t_rd_node *)curr_rd->content)->rd_type = REDIRECT_AM;
				ft_lstclear(&file_list, free);
			}
			else if (file_list != NULL && file_list->content)
				file_list_one(filename, &file_list, &curr_rd);
			else if (file_list == NULL)
				rd_wildcard_none(&curr_rd);
		}
		curr_rd = curr_rd->next;
	}
}

static void	file_list_one(char *filename, t_list **file_list, t_list **curr_rd)
{
	((t_rd_node *)(*curr_rd)->content)->filename = (*file_list)->content;
	free(filename);
	free(*file_list);
}
static void	rd_wildcard_none(t_list **curr_rd)
{	
	int		i;
	char	*str;

	i = 0;
	str = ((t_rd_node *)(*curr_rd)->content)->filename;
	while (str[i])
	{
		if (str[i] == '\12')
			str[i] = '*';
		i++;
	}
}

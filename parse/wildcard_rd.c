/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_rd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:53:56 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 11:24:54 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <histedit.h>
#include <dirent.h>

t_list	*find_wildcard_rd(char *str);

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
			{
				((t_rd_node *)curr_rd->content)->filename = file_list->content;
				free(filename);
				free(file_list);
			}
		}
		curr_rd = curr_rd->next;
	}
}

t_list	*find_wildcard_rd(char *str)
{
	t_list			*wildlist;
	DIR				*dp;
	struct dirent	*entry;

	wildlist = NULL;
	dp = opendir(".");
	if (dp == NULL)
	{
		error_handler(NULL, NULL, "openerror");
		exit(1);
	}
	entry = readdir(dp);
	while (entry != NULL)
	{
		if (is_match(entry->d_name, str))
			make_wildcard_list(&wildlist, entry);
		entry = readdir(dp);
	}
	closedir(dp);
	return (wildlist);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_rd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:53:56 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 12:31:06 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <histedit.h>
#include <dirent.h>

t_list	*find_wildcard_rd(char *str, int *flag);
void	wildcard_rd(t_list **rd_list)
{
	t_list	*curr_rd;
	char	*filename;
	t_list	*file_list;
	int		flag;

	flag = 1;
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
				return ;
			}
			if (file_list != NULL && file_list->content)
			{
				if (flag)
					((t_rd_node *)curr_rd->content)->rd_type = REDIRECT_DIR;
				((t_rd_node *)curr_rd->content)->filename = file_list->content;
				free(filename);
				free(file_list);
			}
		}
		curr_rd = curr_rd->next;
	}
}


t_list	*find_wildcard_rd(char *str, int *flag)
{
	t_list			*wildlist;
	DIR				*dp;
	struct dirent	*entry;

	wildlist = NULL;
	dp = opendir(".");
	if (dp == NULL)
	{
		ft_putstr_fd("openerror", STDOUT_FILENO);
//		ft_printf(1, "openerror");// error 핸들러로 변경
		exit(1);
	}
	entry = readdir(dp);
	while (entry != NULL)
	{
		if (is_match(entry->d_name, str))
		{
			make_wildcard_list(&wildlist, entry);
			if (entry->d_type == DT_DIR)
				*flag = 1;
		}
		entry = readdir(dp);
	}
	closedir(dp);
	return (wildlist);
}
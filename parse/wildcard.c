/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:05:50 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 12:32:01 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <histedit.h>
#include <dirent.h>
#include <stdio.h>

t_list	*find_wildcard_dir(char *str);
void	make_wildcard_list_dir(t_list **wildlist, struct dirent *entry);
void	make_wildcard_list(t_list **wildlist, struct dirent *entry);

void	wildcard(t_list **cmd_list)
{
	t_list		*curr;
	t_cmd_node	*curr_content;

	curr = *cmd_list;
	while (curr)
	{
		curr_content = ((t_cmd_node *)(curr)->content);
		if (curr_content->cmd_list)
			wildcard_cmd(&(curr_content->cmd_list));
		if (curr_content->rd_list)
			wildcard_rd(&(curr_content->rd_list));
		curr = curr->next;
	}
}

t_list	*find_wildcard_dir(char *str)
{
	t_list			*wildlist;
	DIR				*dp;
	struct dirent	*entry;

	str = delete_dir_flag(str);
	dp = opendir(".");
	wildlist = NULL;
	if (dp == NULL)
	{
		ft_putendl_fd("openerror", 1);
		//ft_printf(1, "openerror");
		exit(-1);
	}
	entry = readdir(dp);
	while (entry != NULL)
	{
		if (is_match(entry->d_name, str) && entry->d_type == DT_DIR)
			make_wildcard_list_dir(&wildlist, entry);
		entry = readdir(dp);
	}
	closedir(dp);
	free(str);
	return (wildlist);
}

t_list	*find_wildcard(char *str)
{
	t_list			*wildlist;
	DIR				*dp;
	struct dirent	*entry;
	int				flag;

	wildlist = NULL;
	flag = is_wildcard_dirtory(str);
	if (flag)
		return (find_wildcard_dir(str));
	dp = opendir(".");
	if (dp == NULL)
	{
		ft_printf(1, "openerror");// error 핸들러로 변경
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

void	make_wildcard_list_dir(t_list **wildlist, struct dirent *entry)
{
	char	*name;
	t_list	*new;

	name = ft_strjoin(entry->d_name, "/", 0);
	new = ft_lstnew(name);
	ft_lstadd_back(wildlist, new);
}


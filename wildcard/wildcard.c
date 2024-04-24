/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:05:50 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/24 15:08:17 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <histedit.h>
#include <dirent.h>
#include <stdio.h>

static t_list	*find_wildcard_dir(char *str, char *front);
static void		make_wildcard_list_dir(t_list **wildlist, \
struct dirent *entry, char *front);

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

static t_list	*find_wildcard_dir(char *str, char *front)
{
	t_list			*wildlist;
	DIR				*dp;
	struct dirent	*entry;

	str = delete_dir_flag(str);
	dp = opendir(".");
	wildlist = NULL;
	if (dp == NULL)
	{
		error_handler(NULL, NULL, "openerror");
		exit(-1);
	}
	entry = readdir(dp);
	while (entry != NULL)
	{
		if (is_match(entry->d_name, str) && entry->d_type == DT_DIR)
			make_wildcard_list_dir(&wildlist, entry, front);
		entry = readdir(dp);
	}
	closedir(dp);
	free(str);
	return (wildlist);
}

t_list	*find_wildcard(char *str, char *front)
{
	t_list			*wildlist;
	DIR				*dp;
	struct dirent	*entry;
	int				flag;

	wildlist = NULL;
	flag = is_wildcard_dirtory(str);
	if (flag)
		return (find_wildcard_dir(str, front));
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
			make_wildcard_list(&wildlist, entry, front);
		entry = readdir(dp);
	}
	closedir(dp);
	return (wildlist);
}

void	make_wildcard_list(t_list **wildlist, \
struct dirent *entry, char *front)
{
	char	*name;
	t_list	*new;

	name = ft_strjoin(front, entry->d_name, 0);
	new = ft_lstnew(name);
	ft_lstadd_back(wildlist, new);
}

static void	make_wildcard_list_dir(t_list **wildlist, \
struct dirent *entry, char *front)
{
	char	*name;
	char	*prev;
	t_list	*new;

	prev = ft_strjoin(front, entry->d_name, 0);
	name = ft_strjoin(prev, "/", 0);
	new = ft_lstnew(name);
	ft_lstadd_back(wildlist, new);
	free(prev);
}

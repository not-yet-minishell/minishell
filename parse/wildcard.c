/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:05:50 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/18 20:33:16 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <histedit.h>
#include <dirent.h>
#include <stdio.h>
void	wildcard_rd(t_list **rd_list);
void	wildcard_cmd(t_list **cmd_list);
int		has_wildcard(char *str);
t_list	*find_wildcard(char *str);
int		is_match(char *str, char *pattern);
void	cmd_wildcard_has(t_list **curr_cmd, t_list **cmd_list, t_list *prev, t_list *wild_list);
void	cmd_wildcard_none(t_list **curr_cmd);
int		is_wildcard_dirtory(char *str);
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
			ft_lstclear(&file_list,free);
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

void	wildcard_cmd(t_list **cmd_list)
{
	t_list	*prev;
	t_list	*curr_cmd;
	t_list	*wild_list;

	prev = NULL;
	curr_cmd = *cmd_list;
	wild_list =NULL;
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

void	cmd_wildcard_has(t_list **curr_cmd, t_list **cmd_list, t_list *prev, t_list *wild_list)
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

int	has_wildcard(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\12')
			return (1);
		i++;
	}
	return (0);
}

int		is_wildcard_dirtory(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '/')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] == '/')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

char	*delete_dir_flag(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != '/')
		i++;
	new_str = ft_substr(str, 0, i);
	return (new_str);
}

t_list	*find_wildcard_dir(char *str)
{
	t_list			*wildlist;
	DIR*			dp;
	struct dirent*	entry;

	str = delete_dir_flag(str);
	dp = NULL;
	entry = NULL;
	wildlist = NULL;
	if ((dp=opendir(".")) == NULL)
	{
		ft_printf(1,"openerror");
		exit(-1);
	}
	while ((((entry = readdir(dp))) != NULL))
	{
		if (is_match(entry->d_name, str) && entry->d_type == DT_DIR)
			make_wildcard_list_dir(&wildlist, entry);
	}
	closedir(dp);
	free(str);
	return (wildlist);
}

void	make_wildcard_list_dir(t_list **wildlist, struct dirent *entry)
{
	char	*name;
	t_list	*new;

	name = ft_strjoin(entry->d_name,"/",0);
	new = ft_lstnew(name);
	ft_lstadd_back(wildlist, new);
}

void	make_wildcard_list(t_list **wildlist, struct dirent *entry)
{
	char	*name;
	t_list	*new;

	name = ft_strdup(entry->d_name);
	new = ft_lstnew(name);
	ft_lstadd_back(wildlist, new);
}

t_list	*find_wildcard(char *str)
{
	t_list			*wildlist;
	DIR*			dp;
	struct dirent*	entry;
	int				flag;

	dp = NULL;
	entry = NULL;
	wildlist = NULL;
	flag = is_wildcard_dirtory(str);
	if (flag)
		return (find_wildcard_dir(str));
	if ((dp=opendir(".")) == NULL)
	{
		ft_printf(1,"openerror");// error 핸들러로 변경
		exit(-1);
	}
	while ((((entry = readdir(dp))) != NULL))
	{
		if (is_match(entry->d_name, str))
			make_wildcard_list(&wildlist, entry);
	}
	closedir(dp);
	return (wildlist);
}

int	match_point(char *str, int *sIdx, char *pattern, int *pIdx)
{
	while (str[*sIdx] == '.')
	{
		if (str[*sIdx] == pattern[*pIdx])
		{
			(*sIdx)++;
			(*pIdx)++;
		}
		else
			return (0);
	}
	return (1);
}

int	match_str_pattern(char *str, int *sIdx, char *pattern, int *pIdx)
{
	int	sTempIdx;
	int	starIdx;

	sTempIdx = -1;
	starIdx = -1;
	while (*sIdx < (int)ft_strlen(str))
	{
		if (str[*sIdx] && pattern[*pIdx] && str[*sIdx] == pattern[*pIdx])
		{
			(*sIdx)++;
			(*pIdx)++;
		} 
		else if (pattern[*pIdx] && pattern[*pIdx] == '\12')
		{
			starIdx = (*pIdx);
			sTempIdx = (*sIdx);
			(*pIdx)++;
		}
		else if (starIdx != -1)
		{
			(*pIdx) = starIdx + 1;
			(*sIdx) = ++sTempIdx;
		}
		else
			return (0);
	}
	return (1);
}

int	is_match(char *str, char *pattern)
{
	int	sIdx;
	int	pIdx;

	sIdx = 0;
	pIdx = 0;
	if (match_point(str,&sIdx,pattern,&pIdx) == 0)
		return(0);
	if (match_str_pattern(str,&sIdx,pattern,&pIdx) == 0)
		return (0);
	while (pattern[pIdx] && pattern[pIdx] == '\12')
		pIdx++;
	if (pIdx == (int)ft_strlen(pattern))
		return (1);
	return (0);
}


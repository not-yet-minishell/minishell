/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:05:50 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/18 17:13:59 by soljeong         ###   ########.fr       */
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
	//char	*new_str;
	t_list	*file_list;

	curr_rd = *rd_list;
	while (curr_rd)
	{
		filename = ((t_rd_node *)curr_rd->content)->filename;
		file_list = find_wildcard(filename);
		if (ft_lstsize(file_list) > 1)
		{
			((t_rd_node *)curr_rd->content)->rd_type = REDIRECT_AM;
			// free도 해줘야하고 더 처리가 필요함....
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
	t_list	*temp;

	prev = NULL;
	curr_cmd = *cmd_list;
	wild_list =NULL;
	while (curr_cmd)
	{
		if (has_wildcard(curr_cmd->content))
		{
			wild_list = find_wildcard(curr_cmd->content);
		if (wild_list != NULL)
		{
			temp = curr_cmd;
			ft_lstlast(wild_list)->next = temp->next;

			if (prev)
				prev->next = wild_list;
			else
				*cmd_list = wild_list;
			curr_cmd = wild_list;
			free(temp->content);
			free(temp);
		}
		else{
			int	i = 0;
			char *str = curr_cmd->content;
			while (str[i])
			{
				if (str[i] == '\12')
					str[i] = '*';
				i++;
			}
		}
		}
		prev = curr_cmd;
		if (curr_cmd)
			curr_cmd = curr_cmd->next;
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
	while (str[i] != '/')
		i++;
	if (str[i] == NULL)
		return (0);
	while (str[i] == '/')
		i++;
	if (str[i] == NULL)
		return (1);
	return (0);
}

char	*delete_dir_flag(char *str)
{
	int	i;
	char	*new_str;

	i = 0;
	while (str[i] != '/')
		i++;
	new_str = ft_substr(str, 0, i);
	return (new_str)
}

t_list	*find_wildcard(char *str)
{
	t_list	*wildlist;
	DIR*	dp;
	struct dirent* entry;

	dp = NULL;
	entry = NULL;
	wildlist = NULL;
	if ((dp=opendir(".")) == NULL)
	{
		ft_printf(1,"openerror");// error 핸들러로 변경
		exit(-1);
	}
	while ((((entry = readdir(dp))) != NULL))
	{
		if (is_match(entry->d_name, str))
		{
			char	*name = ft_strdup(entry->d_name);
			t_list *new = ft_lstnew(name);
			ft_lstadd_back(&wildlist, new);
		}
	}
	closedir(dp);
	return (wildlist);
}

int	is_match(char *str, char *pattern)
{
	int	sIdx;
	int	pIdx;
	int	sTempIdx;
	int	starIdx;

	sIdx = 0;
	pIdx = 0;
	sTempIdx = -1;
	starIdx = -1;
	// 처음에 밀어버려
	while (str[sIdx] == '.')
	{
		if (str[sIdx] == pattern[pIdx])
		{
			sIdx++;
			pIdx++;
		}
		else
			return (0);
	}
	while (sIdx < (int)ft_strlen(str))
	{
		if (str[sIdx] && pattern[pIdx] && str[sIdx] == pattern[pIdx])
		{
			sIdx++;
			pIdx++;
		} else if (pattern[pIdx] && pattern[pIdx] == '\12')
		{
			starIdx = pIdx;
			sTempIdx = sIdx;
			pIdx++;
		}else if (starIdx != -1)
		{
			pIdx = starIdx + 1;
			sIdx = ++sTempIdx;
		}
		else
			return (0);
	}
	while (pattern[pIdx] && pattern[pIdx] == '\12')
		pIdx++;
	if (pIdx == (int)ft_strlen(pattern))
		return (1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:41:48 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/15 11:13:59 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_rd_list(t_list *rd);

void	free_pipe_list(t_list *pipelist)
{
	t_list		*rd;
	t_list		*cmd;
	t_cmd_node	*node;
	t_list		*temp;

	while (pipelist != NULL)
	{
		node = pipelist->content;
		rd = node->rd_list;
		cmd = node->cmd_list;
		free_rd_list(rd);
		free_cmd_list(cmd);
		temp = pipelist;
		pipelist = pipelist->next;
		free(temp);
	}
}

static void	free_rd_list(t_list *rd)
{
	t_rd_node	*content;
	t_list		*temp;

	while (rd != NULL)
	{
		content = rd->content;
		free(content->filename);
		free(content);
		temp = rd;
		rd = rd->next;
		free(temp);
	}
}

void	free_cmd_list(t_list *cmd)
{
	t_list	*temp;

	while (cmd != NULL)
	{
		temp = cmd;
		free(cmd->content);
		cmd = cmd->next;
		free(temp);
	}
}

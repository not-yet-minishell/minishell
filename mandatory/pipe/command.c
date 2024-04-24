/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:46:28 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/22 07:47:16 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	start_command(t_list *cmd_list, t_fd *fd_info, t_list *env)
{
	t_list	*rd_node;
	t_list	*exe_cmd;

	rd_node = ((t_cmd_node *)cmd_list->content)->rd_list;
	exe_cmd = ((t_cmd_node *)cmd_list->content)->cmd_list;
	if (fd_info->temp_fd != -1)
	{
		dup2(fd_info->temp_fd, STDIN_FILENO);
		close(fd_info->temp_fd);
	}
	if (fd_info->fds[1] != 0)
	{
		dup2(fd_info->fds[1], STDOUT_FILENO);
		close(fd_info->fds[1]);
	}
	if (fd_info->fds[0] != 0)
		close(fd_info->fds[0]);
	while (rd_node != NULL)
	{
		if (redirect(rd_node->content) == FALSE)
			exit(1);
		rd_node = rd_node->next;
	}
	execute(exe_cmd, env);
}

t_list	*free_and_next_rd(t_list *rd_node)
{
	t_list	*pre;

	pre = rd_node;
	rd_node = rd_node->next;
	free(((t_rd_node *)pre->content)->filename);
	free(pre->content);
	free(pre);
	return (rd_node);
}

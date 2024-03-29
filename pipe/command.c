/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:46:28 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/29 20:42:42 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	start_command(t_list *node, t_fd fd_info)
{
	t_list	*rd_node;
	t_list	*exe_node;

	rd_node = node->content->rd_list;
	exe_node = node->content->exe_list;
	while (rd_node != NULL)
	{
		redirect(rd_node->content);
		rd_node = free_and_next_rd(rd_node);
	}
	while (exe_node != NULL)
	{
		execute(exe_node->content);
		exe_node = free_and_next_exe(exe_node);
	}
}

static t_list	*free_and_next_rd(t_list *rd_node)
{}

static t_list	*free_and_next_exe(t_list *exe_node)
{}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:30:17 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/01 18:03:29 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_fd	*init_fd(void);
static void	delete_cmd_node(t_list *node);
static void	close_fd(t_fd *fd_info);
static void	free_list(t_list *node);

int	start_process(t_list *head, t_list *env)
{
	t_fd	*fd_info;
	int		fork_count;

	fork_count = 0;
	fd_info = init_fd();
	if (head->next == NULL)
		return (one_process(head));
	while (head != NULL)
	{
		if (head->next != NULL)
			pipe(fd_info->fds);
		fd_info->pid = fork();
		fork_count++;
		if (fd_info->pid > 0)
			close_parent_fd(fd_info);
		if (fd_info->pid == 0)
			start_command(head, fd_info, env);
		fd_info->temp_fd = fd_info->fds[0];
		head = delete_and_next_node(head);
	}
	close(fd_info->fds[0]);
	wait_process(fd_info, fork_count);
}

static void	close_parent_fd(t_fd *fd_info)
{
	close(fd_info->fds[1]);
	if (fd_info->temp_fd != -1)
		close(fd_info->temp_fd);
}

static t_list	*delete_and_next_node(t_list *node)
{
	t_list			*temp;
	t_cmd_node		*cmd_node;
	t_list			*rd_list;
	t_list			*temp_rd_list;

	temp = node;
	node = node->next;
	cmd_node = (t_cmd_node *)temp->content;
	rd_list = cmd_node->rd_list;
	while (rd_list != NULL)
	{
		temp_rd_list = rd_list;
		rd_list = rd_list->next;
		free(((t_rd_node *)temp_rd_list->content)->filename);
		free(temp_rd_list->content);
		free(temp_rd_list);
	}
	free_list(cmd_node->cmd_list);
	free(cmd_node);
	free(temp);
	return (node);
}

static void	free_list(t_list *node)
{
	t_list	*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp->content);
		free(temp);
	}
}

static t_fd	*init_fd(void)
{
	t_fd	*init_fd;

	init_fd = (t_fd *)malloc(sizeof(t_fd));
	if (init_fd == NULL)
		exit(1);
	init_fd->temp_fd = -1;
	return (init_fd);
}

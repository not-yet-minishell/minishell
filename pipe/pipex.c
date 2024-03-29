/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:30:17 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/29 19:46:57 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_fd	*init_fd(void);
static void	delete_cmd_node(t_list *node);
static void	close_fd(t_fd *fd_info);

int	start_process(t_list *head)
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
			start_command(head, fd_info);
		fd_info->temp_fd = fd_info->fds[0];
		head = delete_and_next_node(head);
	}
	close(fd_info->fds[0]);
	return (fork_count);
}

static void	close_parent_fd(t_fd *fd_info)
{
	close(fd_info->fds[1]);
	if (fd_info->temp_fd != -1)
		close(fd_info->temp_fd);
}

static t_list	*delete_and_next_node(t_list *node)
{
	t_list	*temp;

	temp = node;
	node = node->next;
	free(temp->content);// 더 프리해야함
	return (node);
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

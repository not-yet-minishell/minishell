/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:30:17 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/15 14:37:51 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_fd	*init_fd(void);
static void	close_parent_fd(t_fd *fd_info);
static int	is_builtin(t_list *node);

int	start_process(t_list *head, t_list *env)
{
	t_fd	*fd_info;
	int		fork_count;

	fork_count = 0;
	fd_info = init_fd();
	if ((head->next) == NULL && (is_builtin(head) == TRUE))
		return (one_process(head, env));
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
	if (fd_info->fds[0] != 0)
		close(fd_info->fds[0]);
	return (wait_process(fd_info, fork_count));
}

static void	close_parent_fd(t_fd *fd_info)
{
	if (fd_info->fds[1] != 0)
		close(fd_info->fds[1]);
	if (fd_info->temp_fd != -1)
		close(fd_info->temp_fd);
}

static t_fd	*init_fd(void)
{
	t_fd	*init_fd;

	init_fd = (t_fd *)malloc(sizeof(t_fd));
	if (init_fd == NULL)
		exit(1);
	init_fd->temp_fd = -1;
	init_fd->fds[0] = 0;
	init_fd->fds[1] = 0;
	return (init_fd);
}

static int	is_builtin(t_list *node)
{
	t_cmd_node	*content;
	t_list		*cmd_list;
	char		*cmd;

	content = node->content;
	cmd_list = content->cmd_list;
	cmd = cmd_list->content;
	if (ft_strncmp(cmd, "exit", 5) == 0 \
	|| ft_strncmp(cmd, "pwd", 4) == 0 \
	|| ft_strncmp(cmd, "cd", 3) == 0 \
	|| ft_strncmp(cmd, "env", 4) == 0 \
	|| ft_strncmp(cmd, "unset", 6) == 0 \
	|| ft_strncmp(cmd, "export", 7) == 0 \
	|| ft_strncmp(cmd, "echo", 5) == 0)
		return (TRUE);
	return (FALSE);
}


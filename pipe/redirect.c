/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:59:20 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/01 16:46:00 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	in_redirect(t_rd_node *node);
static void	out_redirect(t_rd_node *node);
static void	append_redirect(t_rd_node *node);

void	redirect(t_rd_node *node, t_fd *fd_info)
{
	int		type;

	if (fd_info->temp_fd != -1)
		dup2(fd_info->temp_fd, STDIN_FILENO);
	type = node->rd_type;
	if (type == RD_IN)
		in_redirect(node);
	else if (type == RD_OUT)
		out_redirect(node);
	else if (type == RD_APPEND)
		append_redirect(node);
	else
		error_handler("node", NULL, NULL);
}

static void	in_redirect(t_rd_node *node)
{
	int		fd;

	fd = open(node->filename, O_RDONLY);
	if (fd == -1)
		error_handler(node->filename, NULL, 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

static void	out_redirect(t_rd_node *node)
{
	int		fd;

	fd = open(node->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_handler(node->filename, NULL, 0);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

static void	append_redirect(t_rd_node *node)
{
	int		fd;

	fd = open(node->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		error_handler(node->filename, NULL, 0);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

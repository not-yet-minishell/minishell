/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:59:20 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/30 17:50:16 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "pipex.h"

static void	in_redirect(t_rd_node *node);
static void	out_redirect(t_rd_node *node);
static void	append_redirect(t_rd_node *node);
static void	heredoc(t_rd_node *node);

void	redirect(t_rd_node *node, t_fd *fd_info)
{
	enum t_rd_type	type;

	if (fd_info->temp_fd != -1)
		dup2(fd_info->fd, STDIN_FILENO);
	type = node->rd_type;
	if (type == RD_IN)
		in_redirect(node);
	else if (type == RD_HEREDOC)
		heredoc(node);
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
	char	*file_name;

	file_name = node->filename;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_handler(av[1], NULL, 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

static void	out_redirect(t_rd_node *node)
{

}

static void	append_redirect(t_rd_node *node)
{

}

static void	heredoc(t_rd_node *node);
{
	
}

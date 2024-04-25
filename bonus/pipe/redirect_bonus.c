/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:59:20 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 14:15:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	in_redirect(t_rd_node *node);
static int	out_redirect(t_rd_node *node);
static int	append_redirect(t_rd_node *node);
static int	open_heredoc(t_rd_node *node);

int	redirect(t_rd_node *node)
{
	int		type;
	int		flag;

	flag = TRUE;
	type = node->rd_type;
	if (type == REDIRECT_IN)
		flag = in_redirect(node);
	else if (type == REDIRECT_HEREDOC)
		flag = open_heredoc(node);
	else if (type == REDIRECT_OUT)
		flag = out_redirect(node);
	else if (type == REDIRECT_APPEND)
		flag = append_redirect(node);
	else
	{
		error_handler("*", NULL, "ambiguous redirect\n");
		flag = FALSE;
	}
	return (flag);
}

static int	open_heredoc(t_rd_node *node)
{
	int	fd;

	fd = open(node->filename, O_RDONLY);
	if (fd == -1)
	{
		error_handler(node->filename, NULL, NULL);
		return (FALSE);
	}
	unlink(node->filename);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (TRUE);
}

static int	in_redirect(t_rd_node *node)
{
	int		fd;

	fd = open(node->filename, O_RDONLY);
	if (fd == -1)
	{
		error_handler(node->filename, NULL, NULL);
		return (FALSE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	unlink(node->filename);
	return (TRUE);
}

static int	out_redirect(t_rd_node *node)
{
	int		fd;

	fd = open(node->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		error_handler(node->filename, NULL, 0);
		return (FALSE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (TRUE);
}

static int	append_redirect(t_rd_node *node)
{
	int		fd;

	fd = open(node->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		error_handler(node->filename, NULL, 0);
		return (FALSE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (TRUE);
}

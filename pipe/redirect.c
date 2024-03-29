/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:59:20 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/29 20:41:10 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	in_redirect(t_rd_node *node);
void	out_redirect(t_rd_node *node);
void	append_redirect(t_rd_node *node);
void	heredoc(t_rd_node *node);

void	redirect(t_rd_node *node)
{
	enum t_rd_type	type;

	if (type == RD_IN)
		in_redirect(node);
	else if(type == RD_HEREDOC)
		heredoc(node);
	else if(type == RD_OUT)
		out_redirect(node);
	else if(type == RD_APPEND)
		append_redirect(node);
}

void	in_redirect(t_rd_node *node)
{}
void	out_redirect(t_rd_node *node)
{}
void	append_redirect(t_rd_node *node)
{}

void	heredoc(t_rd_node *node);
{}
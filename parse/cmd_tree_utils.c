/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:44:02 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/08 12:51:47 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_rd_node	*new_rd_node(int rd_type, char *filename)
{
	t_rd_node	*rd_node;

	rd_node = malloc(sizeof(t_rd_node *));
	if (!rd_node)
		exit (-1);
	rd_node->rd_type = rd_type;
	rd_node->filename = filename;
	return (rd_node);
}

t_cmd_node	*new_cmd_node(t_list *rd_list, t_list *cmd_list)
{
	t_cmd_node	*cmd_node;

	cmd_node = malloc(sizeof(t_cmd_node *));
	if (!cmd_node)
		exit (-1);
	cmd_node->rd_list = rd_list;
	cmd_node->cmd_list = cmd_list;
	return (cmd_node);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:56:21 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/08 14:20:40 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_cmd(char *cmd)
{
	printf("cmd: %s\n", cmd);
}

void	print_rdnode(t_rd_node *rd_node)
{
	printf("rdtype:%d  rdfilename:%s\n", rd_node->rd_type, rd_node->filename);
}

void	print_pipenode(t_cmd_node *pipenode)
{
	ft_lstiter(pipenode->rd_list, (void *)print_rdnode);
	ft_lstiter(pipenode->cmd_list, (void *)print_cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:54:37 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/18 10:51:19 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	one_process(t_list *node, t_list *env)
{
	char	**cmd;
	t_list	*rd_node;
	t_list	*exe_cmd;
	int		exit_code;

	rd_node = ((t_cmd_node *)node->content)->rd_list;
	exe_cmd = ((t_cmd_node *)node->content)->cmd_list;
	while (rd_node != NULL)
	{
		if (redirect(rd_node->content) == FALSE)
			return (1);
		rd_node = free_and_next_rd(rd_node);
	}
	cmd = make_list_to_array(exe_cmd);
	exit_code = execute_builtin(cmd, env);
	//free_list(node);
	return (exit_code);
}

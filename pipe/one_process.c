/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:54:37 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/20 20:17:08 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	one_process(t_list *node, t_list *env)
{
	char	**cmd;
	t_list	*rd_node;
	t_list	*exe_cmd;
	int		exit_code;
	int		fds[2];

	fds[0] = dup(STDIN_FILENO);
	fds[1] = dup(STDOUT_FILENO);
	rd_node = ((t_cmd_node *)node->content)->rd_list;
	exe_cmd = ((t_cmd_node *)node->content)->cmd_list;
	while (rd_node != NULL)
	{
		if (redirect(rd_node->content) == FALSE)
		{
			dup2(fds[0], STDIN_FILENO);
			dup2(fds[1], STDOUT_FILENO);
			close(fds[0]);
			close(fds[1]);
			change_exit_number(1, env);
			return (1);
		}
		rd_node = rd_node->next;//free_and_next_rd(rd_node);
	}
	cmd = make_list_to_array(exe_cmd);
	exit_code = execute_builtin(cmd, env);
	free(cmd);
	dup2(fds[0], STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[0]);
	close(fds[1]);
	//free_list(node);
	return (exit_code);
}

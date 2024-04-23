/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extends_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:52:03 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 11:05:41 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	extends_env_cmd(t_list *env, t_list *cmd_list);
void	extends_env_rd(t_list *env, t_list *rd_list);

void	extends_env(t_list *env, t_list **cmd_list)
{
	t_list	*curr;

	curr = *cmd_list;
	while (curr)
	{
		extends_env_rd(env, ((t_cmd_node *)(curr)->content)->rd_list);
		extends_env_cmd(env, ((t_cmd_node *)curr->content)->cmd_list);
		curr = curr->next;
	}
}

void	extends_env_rd(t_list *env, t_list *rd_list)
{
	t_list	*curr_rd;
	char	*str;
	char	*new_str;

	curr_rd = rd_list;
	while (curr_rd)
	{
		str = ((t_rd_node *)curr_rd->content)->filename;
		new_str = change_str(str, env);
		((t_rd_node *)curr_rd->content)->filename = new_str;
		free(str);
		curr_rd = curr_rd->next;
	}
}

void	extends_env_cmd(t_list *env, t_list *cmd_list)
{
	t_list	*curr_cmd;
	char	*str;
	char	*new_str;

	curr_cmd = cmd_list;
	while (curr_cmd)
	{
		str = curr_cmd->content;
		new_str = change_str(str, env);
		curr_cmd->content = new_str;
		free(str);
		curr_cmd = curr_cmd->next;
	}
}

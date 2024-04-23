/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:36:18 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/23 11:16:06 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static int	check_unset_cmd(char *cmd, t_list *env_list);
static void	unset_env(char *cmd, t_list *env_list);

void	ft_unset(char **cmd, t_list *env_list)
{
	t_list	*current;
	t_list	*pre;

	change_exit_number(0, env_list);
	while (*cmd != NULL)
	{
		current = env_list->next;
		pre = env_list;
		if (check_unset_cmd(*cmd, env_list) == TRUE)
			unset_env(*cmd, env_list);
		cmd++;
	}
	//change_exit_number(0, env_list);
}

static int	check_unset_cmd(char *cmd, t_list *env_list)
{
	int	idx;

	idx = 0;
	if (*cmd == '=' || (*cmd >= '0' && *cmd <= '9'))
	{
		change_exit_number(1, env_list);
		error_handler("unset", cmd, "not a valid identifier\n");
		return (FALSE);
	}
	while (cmd[idx] != '\0')
	{
		if (cmd[idx] == '-' || cmd[idx] == '=')
		{
			change_exit_number(1, env_list);
			error_handler("unset", cmd, "not a valid identifier\n");
			return (FALSE);
		}
		idx++;
	}
	return (TRUE);
}

static void	unset_env(char *cmd, t_list *env_list)
{
	t_env	*content;
	t_list	*current;
	t_list	*pre;

	current = env_list->next;
	pre = env_list;
	while (current != NULL)
	{
		content = (t_env *)current->content;
		if (ft_strncmp(cmd, content->key, \
		ft_strlen(content->key) + 1) == 0)
		{
			delete_env_node(pre, current);
			break ;
		}
		pre = current;
		current = current->next;
	}
}

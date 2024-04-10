/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:36:18 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/10 19:41:45 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

void	ft_unset(char **cmd, t_list *env_list)
{
	t_env	*content;
	t_list	*current;
	t_list	*pre;

	current = env_list->next;
	pre = env_list;
	if (*cmd == NULL)
		return ;
	while (current != NULL)
	{
		content = current->content;
		if (ft_strncmp(*cmd, content->key, ft_strlen(*cmd) + 1) == 0)
		{
			delete_env_node(pre, env_list);
			break ;
		}
		pre = current;
		current = current->content;
	}
	change_exit_number(0, env_list);
}

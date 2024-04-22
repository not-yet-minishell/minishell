/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:36:18 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/20 21:11:04 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

void	ft_unset(char **cmd, t_list *env_list)
{
	t_env	*content;
	t_list	*current;
	t_list	*pre;

	while (*cmd != NULL)
	{
		current = env_list->next;
		pre = env_list;
		while (current != NULL)
		{
			content = (t_env *)current->content;
			if (ft_strncmp(*cmd, content->key, \
			ft_strlen(content->key) + 1) == 0)
			{
				delete_env_node(pre, current);
				break ;
			}
			pre = current;
			current = current->next;
		}
		cmd++;
	}
	change_exit_number(0, env_list);
}

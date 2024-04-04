/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:36:18 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/04 16:56:04 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

void	ft_unset(char **cmd, t_list *env_list)
{
	char	*key;
	t_env	*content;
	t_list	*head;

	head = env_list;
	key = cmd[1];
	if (key == NULL)
		return ;
	while (env_list != NULL)
	{
		content = env_list->content;
		if (ft_strncmp(key, content->key, ft_strlen(key) + 1) == 0)
		{
			delete_node(&env_list);
			change_exit_number(0, head);
			return ;
		}
		env_list = env_list->content;
	}
	change_exit_number(0, head);
}

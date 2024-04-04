/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:23:50 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/04 16:56:15 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

void	ft_pwd(char **cmd, t_list *env_list)
{
	t_env	*env_node;

	while (env_list != NULL)
	{
		env_node = ((t_env *)env_list->content);
		if (ft_strncmp(env_node->key, "PWD", 4) == 0)
		{
			ft_printf(STDOUT_FILENO, env_node->value);
			change_exit_number(0, env_list);
			break ;
		}
		env_list = env_list->next;
	}
}

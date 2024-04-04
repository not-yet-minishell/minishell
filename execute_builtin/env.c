/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:28:54 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/04 16:31:46 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

void	ft_env(char **cmd, t_list *env_list)
{
	t_list	*temp_list;
	t_env	*content;

	temp_list = env_list->next;
	if (cmd[1] != NULL)
	{
		change_exit_number(1, env_list);
		error_handler(*cmd, cmd[1], NULL);
	}
	while (temp_list != NULL)
	{
		content = temp_list->content;
		if (content->value == NULL)
		{
			temp_list = temp_list->next;
			continue ;
		}
		ft_printf(STDOUT_FILENO, "%s=%s\n", content->key, content->value);
		temp_list = temp_list->next;
	}
	change_exit_number(0, env_list);
}

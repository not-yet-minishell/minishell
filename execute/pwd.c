/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:23:50 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/27 04:28:39 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ft_pwd(t_list *head, t_env *env_list)
{
	free_list(head);
	while (env_list != NULL)
	{
		if (ft_strncmp(env_list->key, "PWD", 4) == 0)
		{
			ft_printf(STDIN_FILENO, env_list->value);
			exit(0);
		}
		env_list = env_list->next;
	}
}

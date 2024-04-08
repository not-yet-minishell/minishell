/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:23:50 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/08 17:10:17 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

void	ft_pwd(char **cmd, t_list *env_list)
{
	t_builtin	*content;

	printf("%s\n", content->pwd);
	change_exit_number(0, env_list);
}

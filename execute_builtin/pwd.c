/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:23:50 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/11 15:11:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

void	ft_pwd(t_list *env_list)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_printf(1, "%s\n", pwd);
	change_exit_number(0, env_list);
	free(pwd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:59:27 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/01 18:04:59 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

void	execute_builtin(char **cmd, t_env *env_list)
{
	if (ft_strncmp(cmd, "exit", 5) == 0)
		ft_exit(cmd, env_list);
	else if (ft_strncmp(cmd, "pwd", 4) == 0)
		ft_pwd(cmd, env_list);
	else if (ft_strncmp(cmd, "cd", 3) == 0)
		ft_cd(cmd, env_list);
	else if (ft_strncmp(cmd, "env", 4) == 0)
		ft_env(cmd, env_list);
	else if (ft_strncmp(cmd, "unset", 6) == 0)
		ft_unset(cmd, env_list);
	else if (ft_strncmp(cmd, "export", 7) == 0)
		ft_export(cmd, env_list);
	else if (ft_strncmp(cmd, "echo", 5) == 0)
		ft_echo(cmd);
}

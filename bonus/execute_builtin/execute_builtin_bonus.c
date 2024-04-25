/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:59:27 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 12:50:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin_bonus.h"

int	execute_builtin(char **cmd, t_list *env_list)
{
	int	exit_num;

	if (*cmd == NULL)
	{
		((t_builtin *)env_list->content)->exit_num = 0;
		return (0);
	}
	if (ft_strncmp(*cmd, "exit", 5) == 0)
		ft_exit(cmd, env_list);
	else if (ft_strncmp(*cmd, "pwd", 4) == 0)
		ft_pwd(env_list);
	else if (ft_strncmp(*cmd, "cd", 3) == 0)
		ft_cd(cmd, env_list);
	else if (ft_strncmp(*cmd, "env", 4) == 0)
		ft_env(cmd, env_list);
	else if (ft_strncmp(*cmd, "unset", 6) == 0)
		ft_unset(cmd + 1, env_list);
	else if (ft_strncmp(*cmd, "export", 7) == 0)
		ft_export(cmd, env_list);
	else if (ft_strncmp(*cmd, "echo", 5) == 0)
		ft_echo(cmd + 1, env_list);
	else
		return (-1);
	exit_num = (((t_builtin *)env_list->content)->exit_num);
	return (exit_num);
}

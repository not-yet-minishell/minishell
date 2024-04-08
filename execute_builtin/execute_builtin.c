/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:59:27 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/08 19:53:08 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static void	free_cmd(char **cmd);

void	execute_builtin(char **cmd, t_list *env_list)
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
		ft_unset(cmd + 1, &env_list);
	else if (ft_strncmp(cmd, "export", 7) == 0)
		ft_export(cmd, env_list);
	else if (ft_strncmp(cmd, "echo", 5) == 0)
		ft_echo(cmd + 1, env_list);
	free_cmd(cmd);
}

static void	free_cmd(char **cmd)
{
	int	idx;

	idx = 0;
	while (cmd[idx] != NULL)
	{
		free(cmd[idx]);
		idx++;
	}
	free(cmd);
}
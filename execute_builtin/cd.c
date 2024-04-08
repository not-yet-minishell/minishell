/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:20:46 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/08 20:43:12 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static void	change_env(t_list *env_list);

void	ft_cd(char	**cmd, t_list *env_list)
{
	char	*dir;
	char	*pwd;

	dir = cmd[1];
	if (access(dir, F_OK) != 1)
	{
		error_handler(*cmd, cmd[1], NULL);
		return ;
	}
	if (chdir(dir) == 0)
	{
		change_env(env_list);
		change_exit_number(0, env_list);
	}
	else
	{
		error_handler(*cmd, NULL, NULL);
		change_exit_number(1, env_list);
	}
}

static void	change_env(t_list *env_list)
{
	char	*add_env;
	char	**cmd[3];

	add_env = ft_strjoin("PWD=", getenv("PWD"), "");
	cmd[0] = "export";
	cmd[1] = add_env;
	cmd[2] = NULL;
	export(cmd, env_list);
	add_env = ft_strjoin("OLDPWD=", getenv("OLDPWD"), "");
	cmd[1] = add_env;
	export(cmd, env_list);
}

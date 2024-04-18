/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:20:46 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/18 10:59:14 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static void	change_env(t_list *env_list, char *old_pwd);
static int	find_env(t_list *env_list, char *key);

void	ft_cd(char	**cmd, t_list *env_list)
{
	char	*dir;
	char	*old_pwd;

	dir = cmd[1];
	old_pwd = getcwd(NULL, 0);
	if (old_pwd == NULL)
		old_pwd = ft_strdup(".");
	if (chdir(dir) == 0)
	{
		change_env(env_list, old_pwd);
		change_exit_number(0, env_list);
	}
	else
	{
		error_handler(*cmd, NULL, NULL);
		change_exit_number(1, env_list);
	}
	free(old_pwd);
}

static int	find_env(t_list *env_list, char *key)
{
	t_env	*content;

	env_list = env_list->next;
	while (env_list != NULL)
	{
		content = env_list->content;
		if (ft_strncmp(content->key, key, ft_strlen(key) + 1) == 0)
			return (TRUE);
		env_list = env_list->next;
	}
	return (FALSE);
}

static void	change_env(t_list *env_list, char *old_pwd)
{
	char	*add_env;
	char	*cmd[3];
	char	*pwd;

	if (find_env(env_list, "OLDPWD") == 1)
	{
		add_env = ft_strjoin("OLDPWD=", old_pwd, '\0');
		cmd[0] = "export";
		cmd[1] = add_env;
		cmd[2] = NULL;
		ft_export(cmd, env_list);
	}
	if (find_env(env_list, "PWD") == TRUE)
	{
		pwd = getcwd(NULL, 0);
		add_env = ft_strjoin("PWD=", pwd, '\0');
		cmd[1] = add_env;
		ft_export(cmd, env_list);
		free(pwd);
	}
}

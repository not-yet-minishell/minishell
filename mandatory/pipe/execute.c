/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:59:34 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/24 09:30:03 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_which(char **exe, t_list *env);
static void	exec_cmd(char **exe, char **env_array, t_list *env);
static int	check_access(char *command, char **argument, \
	char *path, char **exe_env);
static void	is_dir(char *path);

void	execute(t_list *node, t_list *env)
{
	char	**cmd;
	char	**env_array;
	int		exit_code;

	if (node == NULL)
		exit(0);
	env_array = find_path_to_array(env);
	cmd = make_list_to_array(node);
	exit_code = execute_builtin(cmd, env);
	if (exit_code != -1)
		exit(exit_code);
	check_which(cmd, env);
	exec_cmd(cmd, env_array, env);
}

static void	check_which(char **exe, t_list *env)
{
	char	*cmd;
	int		idx;
	char	**exe_env;

	(void)env;
	idx = 0;
	cmd = *exe;
	if (!((ft_strchr(cmd, '/') || \
	(ft_strncmp(cmd, "./", 2) == 0)) && access(cmd, F_OK) != -1))
		return ;
	if (access(cmd, X_OK) == -1)
	{
		error_handler(cmd, NULL, NULL);
		exit(126);
	}
	while (cmd[idx] != '\0')
	{
		if (cmd[idx++] == ' ')
			exit(0);
	}
	exe_env = make_env_array(env);
	execve(*exe, exe, exe_env);
	is_dir(exe[0]);
	error_handler(exe[0], NULL, NULL);
	exit(127);
}

static void	exec_cmd(char **exe, char **env_array, t_list *env)
{
	int		idx;
	char	*command;
	char	**exe_env;

	if (ft_strchr(exe[0], '/') || (ft_strncmp(exe[0], "./", 2) == 0))
	{
		error_handler(exe[0], NULL, "No such file or directory\n");
		exit(127);
	}
	exe_env = make_env_array(env);
	idx = 0;
	while (env_array != NULL && env_array[idx])
	{
		command = ft_strjoin(env_array[idx], exe[0], '/');
		check_access(command, exe, env_array[idx], exe_env);
		free(command);
		idx++;
	}
	error_handler(exe[0], NULL, "command not found\n");
	exit(127);
}

static void	is_dir(char *path)
{
	struct stat	dirstat;

	if (stat(path, &dirstat) == -1)
		return ;
	if (S_ISDIR(dirstat.st_mode))
	{
		error_handler(path, NULL, "is a directory\n");
		exit(126);
	}
	return ;
}

static int	check_access(char *command, char **argument, \
	char *path, char **exe_env)
{
	char	*access_path;
	int		exit_no;

	access_path = ft_strjoin(path, argument[0], '/');
	if (ft_strncmp(argument[0], "exit", 5) == 0)
	{
		exit_no = *argument[1] - '0';
		exit(exit_no);
	}
	if (access(access_path, X_OK) != -1)
		execve(command, argument, exe_env);
	free(access_path);
	return (-1);
}

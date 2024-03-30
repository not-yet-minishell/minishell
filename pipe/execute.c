/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:59:34 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/30 17:10:47 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_builtin(char **exe, char **env_array, t_list **env);
static void	check_which(char **exe, char **env_array);
static void	exec_cmd(char **exe, char **env_array);

void	execute(t_list *node, t_list *env)
{
	char	**cmd;
	char	**env_array;

	env_array = find_path_to_array(env);
	cmd = make_list_to_array(node);
	execute_builtin(cmd, env);
	check_which(cmd, env_array);
	exec_cmd(cmd, env_array);
}

static void	check_which(char **exe, char **env_array)
{
	char	*cmd;
	int		idx;
	char	*exe_cmd[2];

	idx = 0;
	if (exe[1] != NULL)
		return ;
	cmd = *exe;
	if (!((ft_strchr(cmd, '/') || (ft_strncmp(cmd, "./", 2) == 0)) && \
	access(cmd, F_OK) != -1))
		return ;
	if (access(arg, X_OK) == -1)
		error_handler(arg, NULL, 126);
	while (arg[idx] != '\0')
	{
		if (arg[idx] == ' ')
			exit(0);
		idx++;
	}
	execve(*exe, exe, env_array);
}

static void	exec_cmd(char **exe, char **env_array)
{
	int		idx;
	char	*command;

	idx = 0;
	while (env_array[idx])
	{
		command = ft_strjoin(env_array[idx], exe[0], '/');
		if (check_access(command, exe, idx, env_array) != -1)
			break ;
		free(command);
		idx++;
	}
	error_handler(exe_ptr[0], "command not found\n", 127);
}

int	check_access(char *command, char **argument, int idx, char **env_array)
{
	char	*access_path;
	int		exit_no;
	char	*path;

	path = env_array[idx];
	access_path = ft_strjoin(path, argument[0], '/');
	if (ft_strncmp(argument[0], "exit", 5) == 0)
	{
		exit_no = *argument[1] - '0';
		exit(exit_no);
	}
	if (access(access_path, X_OK) != -1)
		execve(command, argument, env_array);
	free(access_path);
	return (-1);
}

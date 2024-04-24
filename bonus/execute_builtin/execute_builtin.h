/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:56:57 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/23 11:00:26 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_BUILTIN_H
# define EXECUTE_BUILTIN_H
# define FALSE -1
# define TRUE 1

# include "../minishell.h"

void	free_list(t_list *head);
void	ft_exit(char **cmd, t_list *env_list);
int		execute_builtin(char **cmd, t_list *env_list);
void	change_exit_number(int exit_num, t_list *env_list);
void	ft_export(char **cmd, t_list *env_list);
void	ft_unset(char **cmd, t_list *env_list);
void	ft_export(char **cmd, t_list *env_list);
void	delete_env_node(t_list *pre, t_list *current);
void	ft_cd(char	**cmd, t_list *env_list);
void	ft_echo(char **cmd, t_list *env_list);
void	ft_env(char **cmd, t_list *env_list);
void	ft_pwd(t_list *env_list);
void	free_array(char **arr);
int		check_export_cmd(char *cmd, t_list *env_list);

#endif
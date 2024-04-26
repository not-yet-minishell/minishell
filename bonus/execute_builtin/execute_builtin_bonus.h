/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:57:48 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/27 00:59:15 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_BUILTIN_BONUS_H
# define EXECUTE_BUILTIN_BONUS_H

# define FALSE -1
# define TRUE 1

# include "../minishell_bonus.h"

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
int	check_valid_key(char *cmd);

#endif
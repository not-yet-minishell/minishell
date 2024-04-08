/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:56:57 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/08 20:25:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_BUILTIN_H
# define EXECUTE_BUILTIN_H
# define FALSE -1
# define TRUE 1

# include "../parse/parse_env.h"
# include "../minishell.h"

void	free_list(t_list *head);
void	ft_exit(char **cmd, t_list *env_list);
void	execute_builtin(char **cmd, t_list *env_list);
void	change_exit_number(int exit_num, t_list *env_list);
void	export(char **cmd, t_list *env_list);
void	unset(char **cmd, t_list *env_list);
void	export(char **cmd, t_list *env_list);
void	delete_env_node(t_list *pre, t_list *current);

#endif
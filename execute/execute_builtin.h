/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:56:57 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/30 17:38:07 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# define FALSE -1
# define TRUE 1
# include "../minishell.h"

void	free_list(t_list *head);
void	ft_exit(t_list *head, t_env *env_list);
void	error_handler(char *cmd_name, char *option_name, char *msg);
int		execute_builtin(t_list *head, t_env *env_list);

#endif
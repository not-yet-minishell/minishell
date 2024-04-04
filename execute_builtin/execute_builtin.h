/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:56:57 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/04 18:03:57 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_BUILTIN_H
# define EXECUTE_BUILTIN_H
# define FALSE -1
# define TRUE 1

# include "../parse/parse_env.h"
# include "../minishell.h"

void	free_list(t_list *head);
void	ft_exit(t_list *head, t_env *env_list);
void	error_handler(char *cmd_name, char *option_name, char *msg);
void	execute_builtin(t_list *head, t_env *env_list);

#endif
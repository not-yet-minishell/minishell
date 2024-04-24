/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:00:55 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/24 09:28:46 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ENV_H
# define PARSE_ENV_H
# include "../minishell.h"

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_builtin
{
	char	*pwd;
	int		exit_num;
}	t_builtin;

t_list	*parse_env(char *env[]);
t_list	*select_sort(t_list *env_list);
void	add_oldpwd(t_list *env);

#endif
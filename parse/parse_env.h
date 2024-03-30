/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:00:55 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/30 17:39:45 by yeoshin          ###   ########.fr       */
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

t_list	*parse_env(char *env[]);

#endif
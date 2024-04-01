/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:00:55 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/29 19:13:57 by soljeong         ###   ########.fr       */
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

void	*ft_malloc(int size);
t_list	*parse_env(char *env[]);

#endif
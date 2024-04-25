/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extends_find_env_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:08:03 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 11:16:27 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*extends_find_env_firstnum(char *str, int *i, int *env_start)
{
	(*i)++;
	*env_start = *i;
	while (ft_isalnum((int)str[*i]))
		(*i)++;
	return (ft_substr(str, *env_start, (*i) - *env_start));
}

void	extdns_find_exit_code(int *i, char **value, t_list *env)
{
	*value = find_exit_code(env);
	(*i)++;
}

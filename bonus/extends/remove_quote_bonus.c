/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 12:50:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

char	*remove_dobulequote(char *str, int *i, t_list *env)
{
	char	*removed_str;
	int		start;

	(*i)++;
	start = (*i);
	while (str[*i])
	{
		if (str[*i] == '\"')
		{
			removed_str = ft_substr(str, start, (*i) - start);
			(*i)++;
			return (chage_env_key_to_value(removed_str, env));
		}
		(*i)++;
	}
	return (NULL);
}

char	*remove_singlequote(char *str, int *i)
{
	char	*removed_str;
	int		start;

	(*i)++;
	start = (*i);
	while (str[*i])
	{
		if (str[*i] == '\'')
		{
			removed_str = ft_substr(str, start, (*i) - start);
			(*i)++;
			return (removed_str);
		}
		(*i)++;
	}
	return (NULL);
}

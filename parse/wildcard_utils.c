/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:55:06 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/19 11:21:55 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	has_wildcard(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\12')
			return (1);
		i++;
	}
	return (0);
}

int	is_wildcard_dirtory(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '/')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] == '/')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

char	*delete_dir_flag(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != '/')
		i++;
	new_str = ft_substr(str, 0, i);
	return (new_str);
}

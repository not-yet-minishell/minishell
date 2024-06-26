/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:06:48 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 12:50:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

void	str_temp_join(char **new, char *temp)
{
	char	*prev;

	prev = *new;
	*new = ft_strjoin(prev, temp, 0);
	free(prev);
	free(temp);
}

void	str_divide_join(char **new, char *str, int start, int i)
{
	char	*temp;
	char	*prev;

	temp = ft_substr(str, start, i - start);
	prev = *new;
	(*new) = ft_strjoin(prev, temp, 0);
	free(prev);
	if (temp)
		free(temp);
}

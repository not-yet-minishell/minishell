/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:06:48 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/15 19:37:32 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

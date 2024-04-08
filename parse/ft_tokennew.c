/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokennew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:25:10 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/08 18:57:12 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_tokennew(void *str, int tokentype)
{
	t_token	*new;

	new = ft_malloc(sizeof(t_token));
	if (new == NULL)
		return (NULL);
	new->str = str;
	new->type = tokentype;
	return (new);
}

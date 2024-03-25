/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokennew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:25:10 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/25 11:27:21 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

t_token	*ft_tokennew(void *str, int tokennum)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		return (NULL);
	new->str = str;
	new->token = tokennum;
	return (new);
}

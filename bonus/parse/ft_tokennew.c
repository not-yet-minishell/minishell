/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokennew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:25:10 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/22 11:52:14 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_tokennew(char *str, int tokentype)
{
	t_token	*new;

	new = ft_malloc(sizeof(t_token));
	new->str = str;
	new->type = tokentype;
	return (new);
}

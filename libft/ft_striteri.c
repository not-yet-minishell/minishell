/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:01:39 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/05 20:48:08 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	length;
	unsigned int	count;

	count = 0;
	if (f == NULL || s == NULL)
		return ;
	length = ft_strlen((const char *)s);
	while (count < length)
	{
		f(count, &s[count]);
		count ++;
	}
}

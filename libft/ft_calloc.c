/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:32:48 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/22 16:24:14 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	over;

	over = ~(size_t) 0;
	if (size > 0)
	{
		if ((over / size) < count)
			return (NULL);
	}
	arr = malloc(size * count);
	if (!arr)
		return (arr);
	ft_bzero(arr, size * count);
	return (arr);
}

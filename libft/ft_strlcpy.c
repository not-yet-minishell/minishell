/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:22:26 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/19 22:32:45 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (idx + 1 < size)
	{
		if (src[idx] == '\0')
			break ;
		dest[idx] = src[idx];
		idx ++;
	}
	dest[idx] = '\0';
	return (len);
}

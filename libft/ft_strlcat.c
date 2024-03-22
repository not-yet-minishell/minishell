/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:24:16 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/05 18:07:39 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	idx_d;
	size_t	idx_s;
	size_t	ret_len;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	idx_s = 0;
	idx_d = ft_strlen(dest);
	ret_len = ft_strlen(src) + ft_strlen(dest);
	if (ft_strlen(dest) >= size)
		return (ft_strlen(src) + size);
	else
	{
		while (idx_d < size - 1)
		{
			if (src[idx_s] == '\0')
				break ;
			dest[idx_d] = src[idx_s];
			idx_s ++;
			idx_d ++;
		}
		dest[idx_d] = '\0';
		return (ret_len);
	}
}

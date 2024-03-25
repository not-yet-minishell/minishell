/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:25:10 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/19 23:07:13 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			count;

	count = 0;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (len == 0)
		return (dst);
	while (count ++ < len - 1)
	{
		temp_dst ++;
		temp_src ++;
	}
	count = 0;
	while (count ++ < len)
	{
		*temp_dst = *temp_src;
		temp_dst --;
		temp_src --;
	}
	return (dst);
}

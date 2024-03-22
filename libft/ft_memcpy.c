/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:25:07 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/14 12:21:05 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			count;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	void			*ret_temp;

	count = 0;
	ret_temp = dst;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst == 0 && temp_src == 0)
		return (dst);
	while (count < len)
	{
		*temp_dst = *temp_src;
		temp_dst ++;
		temp_src ++;
		count ++;
	}
	return (ret_temp);
}

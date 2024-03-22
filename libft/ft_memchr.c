/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:10:05 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/14 12:40:02 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int find, size_t len)
{
	size_t			count;
	void			*temp;
	unsigned char	*check;

	count = 0;
	temp = NULL;
	check = (unsigned char *)string;
	while (count < len)
	{
		if (*check == (unsigned char)find)
		{
			temp = (void *)check;
			break ;
		}
		count ++;
		check ++;
	}
	return (temp);
}

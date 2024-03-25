/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:25:12 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/19 22:30:55 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int num, size_t len)
{
	size_t			count;
	unsigned char	*string;

	string = (unsigned char *)pointer;
	count = 0;
	while (count < len)
	{
		*string = (unsigned char)num;
		string++;
		count++;
	}
	return (pointer);
}

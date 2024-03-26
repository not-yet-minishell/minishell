/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:12:04 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/04 17:13:11 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptos(unsigned long long pointer, int *return_len, int fd)
{
	unsigned long long	len;
	unsigned long long	temp;

	temp = pointer;
	len = 1;
	if (write(fd, "0x", 2) == -1)
		return (0);
	(*return_len) += 2;
	while (temp > 15)
	{
		temp /= 16;
		len *= 16;
	}
	while (len > 0)
	{
		if (write(fd, &"0123456789abcdef"[pointer / len], 1) == -1)
			return (0);
		(*return_len)++;
		pointer %= len;
		len /= 16;
	}
	return (1);
}

int	print_c(char c, int *return_len, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (0);
	(*return_len)++;
	return (1);
}

int	print_s(void *s, int *return_len, int fd)
{
	char	*str;

	str = (char *)s;
	if (str == NULL)
	{
		if (write(fd, "(null)", 6) == -1)
			return (0);
		(*return_len) += 6;
		return (1);
	}
	while (*str)
	{
		if (write(fd, str, 1) == -1)
			return (0);
		(*return_len)++;
		str ++;
	}
	return (1);
}

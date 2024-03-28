/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:18:07 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/04 17:13:23 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_itos(int n, int *return_len, int fd)
{
	long long	num;
	int			len;
	char		c;

	len = 1;
	num = (long long)n;
	if (num < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (0);
		num *= -1;
		(*return_len)++;
	}
	while (num / len > 9)
		len = len * 10;
	while (len >= 1)
	{
		c = (char)(num / len) + '0';
		if (write(fd, &c, 1) == -1)
			return (0);
		num %= len;
		len /= 10;
		(*return_len)++;
	}
	return (1);
}

int	print_xtos(unsigned int num, int *return_len, char flag, int fd)
{
	if (flag == 'x')
		return (write_hex_x(num, return_len, fd));
	if (flag == 'X')
		return (write_hex_bigx(num, return_len, fd));
	return (0);
}

int	write_hex_x(unsigned int num, int *return_len, int fd)
{
	int				len;
	unsigned int	temp;

	temp = num;
	len = 1;
	while (temp > 15)
	{
		temp /= 16;
		len *= 16;
	}
	while (len > 0)
	{
		if (write(fd, &"0123456789abcdef"[num / len], 1) == -1)
			return (0);
		(*return_len)++;
		num %= len;
		len /= 16;
	}
	return (1);
}

int	write_hex_bigx(unsigned int num, int *return_len, int fd)
{
	int				len;
	unsigned int	temp;

	temp = num;
	len = 1;
	while (temp > 15)
	{
		temp /= 16;
		len *= 16;
	}
	while (len > 0)
	{
		if (write(fd, &"0123456789ABCDEF"[num / len], 1) == -1)
			return (0);
		(*return_len)++;
		num %= len;
		len /= 16;
	}
	return (1);
}

int	print_utos(unsigned int num, int *return_len, int fd)
{
	int		len;
	char	c;

	len = 1;
	while (num / len > 9)
		len *= 10;
	while (len >= 1)
	{
		c = num / len + '0';
		if (write(fd, &c, 1) == -1)
			return (0);
		num %= len;
		len /= 10;
		(*return_len)++;
	}
	return (1);
}

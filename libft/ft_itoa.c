/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:07:06 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/29 16:42:43 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_str(char *str, int len, long long n, int flag)
{
	int	count;
	int	temp;

	count = 0;
	if (n < 0)
		n *= -1;
	while (count < len)
	{
		str[len - count - 1] = "0123456789"[n % 10];
		count ++;
		temp = n / 10;
		n = temp;
	}
	if (flag == 0)
		str[0] = '-';
	str[len] = '\0';
	return (str);
}

static char	*zero(void)
{
	char	*str;

	str = (char *)malloc(2);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int				length;
	long long		temp;
	char			*ret;
	int				flag;

	length = 0;
	flag = 1;
	temp = (long long)n;
	if (n == 0)
		return (zero());
	if (temp < 0)
	{
		flag = 0;
		temp *= -1;
		length += 1;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		length += 1;
	}
	ret = (char *)malloc(length + 1);
	if (ret == NULL)
		return (NULL);
	return (make_str(ret, length, (long long)n, flag));
}

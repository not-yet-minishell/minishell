/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:13:46 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/05 20:51:54 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	length;
	unsigned int	count;
	char			*ret_str;

	if (f == NULL || s == NULL)
		return (NULL);
	count = 0;
	length = ft_strlen(s);
	ret_str = (char *)malloc(length + 1);
	if (ret_str == NULL)
		return (NULL);
	while (count < length)
	{
		ret_str[count] = f(count, s[count]);
		count ++;
	}
	ret_str[length] = '\0';
	return (ret_str);
}

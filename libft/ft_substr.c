/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:52:34 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/05 20:49:09 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	count;

	count = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (len < 0)
		return ((char *)malloc(0));
	if ((unsigned int)ft_strlen(s) <= start)
	{
		string = (char *)malloc(1);
		if (string == NULL)
			return (NULL);
		*string = '\0';
		return (string);
	}
	string = (char *)malloc(len + 1);
	if (string == NULL)
		return (NULL);
	while (count < len)
		string[count ++] = s[start ++];
	string[count] = '\0';
	return (string);
}

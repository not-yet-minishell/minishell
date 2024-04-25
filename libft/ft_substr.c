/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:52:34 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 11:30:46 by yeoshin          ###   ########.fr       */
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
		return ((char *)ft_malloc(0));
	if ((unsigned int)ft_strlen(s) <= start)
	{
		string = (char *)ft_malloc(1);
		*string = '\0';
		return (string);
	}
	string = (char *)ft_malloc(len + 1);
	while (count < len)
		string[count ++] = s[start ++];
	string[count] = '\0';
	return (string);
}

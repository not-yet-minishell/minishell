/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:46:29 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/05 18:09:23 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			count;
	size_t			len_needle;
	int				check;
	char			*temp_hay;

	if (haystack == NULL && len == 0)
		return (NULL);
	check = ft_strlen(haystack);
	temp_hay = (char *)haystack;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	len_needle = ft_strlen(needle);
	count = len - len_needle + 1;
	while (count -- > 0 && *temp_hay != '\0')
	{
		check = (ft_strncmp(temp_hay, needle, len_needle));
		if (check == 0)
			return ((char *)temp_hay);
		temp_hay ++;
	}
	return (NULL);
}

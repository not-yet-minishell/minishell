/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:25:17 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/21 17:56:10 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char		*cpy;
	char		*temp;
	int			len;

	len = ft_strlen(str);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	temp = cpy;
	while (*str)
	{
		*cpy = (char)*str;
		str ++;
		cpy ++;
	}
	*cpy = '\0';
	return ((char *)temp);
}

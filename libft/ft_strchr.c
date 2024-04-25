/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:56:54 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/14 10:58:50 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int find)
{
	unsigned char	*temp_string;
	unsigned char	temp_int;

	temp_string = (unsigned char *)string;
	temp_int = (unsigned char)find;
	while (*temp_string)
	{
		if (*temp_string == temp_int)
			break ;
		temp_string ++;
	}
	if (*temp_string == temp_int)
		return ((char *)temp_string);
	if (*temp_string == '\0')
		return (NULL);
	return ((char *)temp_string);
}

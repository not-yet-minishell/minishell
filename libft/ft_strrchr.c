/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:01:56 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/22 16:14:05 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int find)
{
	char			*temp;
	unsigned char	*check;

	temp = NULL;
	check = (unsigned char *)string;
	while (*check)
	{
		if (*check == (unsigned char)find)
			temp = (char *)check;
		check ++;
	}
	if (*check == (unsigned char)find)
		temp = (char *)check;
	return (temp);
}

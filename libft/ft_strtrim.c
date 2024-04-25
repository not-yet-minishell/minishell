/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:29:34 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 11:30:46 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*string;
	char	*ret_string;
	int		idx;

	if (s1 == NULL || set == NULL)
		return (NULL);
	idx = 0;
	string = (char *)s1;
	start = 0;
	end = 0;
	while (ft_strchr(set, (int)string[start]) != NULL && string[start] != '\0')
		start ++;
	if (start == (int)ft_strlen(s1))
		return (ft_strdup(""));
	while (ft_strchr(set, (int)string[ft_strlen(s1) - end - 1]) != NULL)
		end ++;
	ret_string = (char *)ft_malloc(ft_strlen(s1) - end - start + 1);
	if (ret_string == NULL)
		return (NULL);
	while (start <= (int)ft_strlen(s1) - end - 1)
		ret_string[idx ++] = s1[start ++];
	ret_string[idx] = '\0';
	return (ret_string);
}

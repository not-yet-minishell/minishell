/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:42:16 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 11:30:46 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, char const a)
{
	char			*ret_str;
	int				count_ret;
	int				count;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (a != '\0')
		count++;
	ret_str = ft_malloc(count);
	if (ret_str == NULL)
		return (NULL);
	count = -1;
	count_ret = 0;
	while (s1[++ count])
		ret_str[count_ret ++] = s1[count];
	if (a != '\0')
		ret_str[count_ret++] = a;
	count = -1;
	while (s2[++ count])
		ret_str[count_ret ++] = s2[count];
	ret_str[count_ret] = '\0';
	return (ret_str);
}

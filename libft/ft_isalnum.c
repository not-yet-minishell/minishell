/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:24:52 by yeoshin           #+#    #+#             */
/*   Updated: 2023/10/13 22:41:34 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alnum)
{
	if (alnum >= 65 && alnum <= 90)
		return (1);
	if (alnum >= 97 && alnum <= 122)
		return (1);
	if (alnum >= 48 && alnum <= 57)
		return (1);
	return (0);
}

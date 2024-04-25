/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:25:43 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 12:36:22 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_malloc(int size)
{
	void	*content;

	content = malloc(size);
	if (content == NULL)
		exit (1);
	return (content);
}

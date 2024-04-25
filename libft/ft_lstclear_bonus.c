/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:19 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/09 19:18:33 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pre;
	t_list	*now;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	now = *lst;
	*lst = NULL;
	while (now->next != NULL)
	{
		pre = now;
		now = now->next;
		ft_lstdelone(pre, del);
	}
	ft_lstdelone(now, del);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:19 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/01 15:50:39 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (!*lst)
		return ;
	while (*lst)
	{
		head = *lst;
		del(head->content);
		*lst = head->next;
		free(head);
	}
	*lst = 0;
}

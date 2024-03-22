/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:43:32 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/05 20:33:42 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset(t_list *set, void (*del)(void *))
{
	t_list	*temp;

	while (set != NULL)
	{
		temp = set->next;
		del(set->content);
		free(set);
		set = temp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*check_f;
	t_list	*temp;
	t_list	*new;
	void	*content;

	new = NULL;
	while (lst != NULL && f != NULL && del != NULL)
	{
		temp = lst->next;
		content = f(lst->content);
		check_f = ft_lstnew(content);
		if (check_f == NULL)
		{
			reset(new, del);
			del(content);
			return (NULL);
		}
		if (new == NULL)
			ft_lstadd_front(&new, check_f);
		else
			ft_lstadd_back(&new, check_f);
		lst = temp;
	}
	return (new);
}

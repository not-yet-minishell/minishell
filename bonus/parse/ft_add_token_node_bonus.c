/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token_node_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:57:20 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 12:50:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

void	ft_add_token_node(t_list *head, char *str, int tokentype)
{
	t_list	*new_node;
	t_token	*content;

	content = ft_tokennew(str, tokentype);
	if (!content)
		ft_lstclear(&head, (void *)ft_del_token_node);
	new_node = ft_lstnew(content);
	ft_lstadd_back(&head, new_node);
}

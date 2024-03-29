/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:57:20 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/26 12:44:07 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_add_token_node(t_list *head, char *str, int tokennum)
{
	t_list	*new_node;
	t_token	*content;

	content = ft_tokennew(str, tokennum);
	if (!content)
		ft_lstclear(&head, (void *)ft_del_token_node);
	new_node = ft_lstnew(content);
	ft_lstadd_back(&head, new_node);
}

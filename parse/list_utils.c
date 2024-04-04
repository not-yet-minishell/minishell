/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:13:34 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/02 14:19:05 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	list_shift(t_list **list)
{
	t_list	*tmp;

	if (list == NULL || *list == NULL)
		return ;
	tmp = *list;
	*list = (*list)->next;
	free(tmp);
}

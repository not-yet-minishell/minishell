/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_token_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:44:09 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/10 20:18:52 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_del_token_node(t_token *node)
{
	if (!node)
		return ;
	//free(node->str);
	free(node);
}

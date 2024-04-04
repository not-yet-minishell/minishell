/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:10:51 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/01 18:06:03 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	print_node(t_token *node)
{
	if (!node)
		return ;
	printf("str : %s\n", node->str);
	printf("token : %d\n", node->type);
}

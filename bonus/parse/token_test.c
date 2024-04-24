/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:10:51 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/24 10:44:38 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../printf/ft_printf.h"

void	print_node(t_token *node)
{
	if (!node)
		return ;
	ft_printf(1, "token : %d\n", node->type);
	ft_printf(1, "str : %s\n", node->str);
}

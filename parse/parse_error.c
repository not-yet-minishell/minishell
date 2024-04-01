/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:37:19 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/29 18:14:24 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../execute/execute.h"

void	parse_error(void)
{
	error_handler(NULL, NULL, "syntax error near unexpected token\n");
}

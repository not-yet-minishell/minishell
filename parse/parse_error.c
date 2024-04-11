/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:37:19 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/09 10:46:45 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../execute_builtin/execute_builtin.h"

void	error_handler(char *cmd_name, char *option_name, char *msg);

void	parse_error(void)
{
	error_handler(NULL, NULL, "syntax error near unexpected token\n");
}

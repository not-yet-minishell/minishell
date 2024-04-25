/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:37:19 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 12:50:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include "../execute_builtin/execute_builtin_bonus.h"

void	error_handler(char *cmd_name, char *option_name, char *msg);

void	parse_error(void)
{
	error_handler(NULL, NULL, "syntax error near unexpected token\n");
}

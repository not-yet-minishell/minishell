/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:00:13 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/18 18:31:27 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "minishell.h"

void	error_handler(char *cmd_name, char *option_name, char *msg)
{
	ft_printf(STDERR_FILENO, "minishell: ");
	if (cmd_name != NULL)
		ft_printf(STDERR_FILENO, "%s: ", cmd_name);
	if (option_name != NULL)
		ft_printf(STDERR_FILENO, "%s: ", option_name);
	if (msg != NULL)
		ft_printf(STDERR_FILENO, "%s", msg);
	else
	 	ft_printf(STDERR_FILENO, "%s\n", strerror(errno));
}
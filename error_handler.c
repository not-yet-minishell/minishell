/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:00:13 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/24 09:10:28 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "minishell.h"

void	error_handler(char *cmd_name, char *option_name, char *msg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (cmd_name != NULL)
	{
		ft_putstr_fd(cmd_name, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (option_name != NULL)
	{
		ft_putstr_fd(option_name, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (msg != NULL)
		ft_putstr_fd(msg, STDERR_FILENO);
	else
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

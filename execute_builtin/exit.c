/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:24:51 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/11 08:56:01 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static int	isnum(char *content);

void	ft_exit(char **cmd, t_list *env_list)
{
	int		exit_num;

	if (cmd[1] == NULL)
	{
		change_exit_number(0, env_list);
		exit(0);
	}
	exit_num = ft_atoi(cmd[1]);
	ft_printf(STDOUT_FILENO, "%s\n", *cmd);
	if (isnum(cmd[1]) == FALSE || exit_num == FALSE)
	{
		exit_num = 255;
		change_exit_number(exit_num, env_list);
		error_handler(*cmd, cmd[1], NULL);
		exit(exit_num);
	}
	if (cmd[2] != NULL)
	{
		error_handler(*cmd, NULL, NULL);
		free_array(cmd);
		change_exit_number(1, env_list);
	}
	change_exit_number(exit_num, env_list);
	exit(exit_num);
}

static int	isnum(char *content)
{
	if (*content == '\0')
		return (FALSE);
	if (*content == '-' || *content == '+')
		content ++;
	while (*content)
	{
		if (*content >= '0' && *content <= '9')
			content++;
		else
			return (FALSE);
	}
	return (TRUE);
}

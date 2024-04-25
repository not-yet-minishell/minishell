/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utile_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:48:43 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 12:50:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin_bonus.h"

int	check_export_cmd(char *cmd, t_list *env_list)
{
	int	idx;

	idx = 0;
	if (*cmd == '=' || (*cmd >= '0' && *cmd <= '9'))
	{
		change_exit_number(1, env_list);
		error_handler("export", cmd, "not a valid identifier\n");
		return (FALSE);
	}
	while (cmd[idx] && cmd[idx] != '=')
	{
		if (cmd[idx] == '-')
		{
			change_exit_number(1, env_list);
			error_handler("export", cmd, "not a valid identifier\n");
			return (FALSE);
		}
		idx++;
	}
	return (TRUE);
}

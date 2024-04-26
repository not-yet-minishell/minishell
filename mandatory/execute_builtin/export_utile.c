/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:48:43 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/27 00:25:01 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

int	check_export_cmd(char *cmd, t_list *env_list)
{
	int	idx;

	idx = 0;
	if (*cmd == '=' || (*cmd >= '0' && *cmd <= '9') || \
		check_valid_key(cmd) == FALSE)
	{
		change_exit_number(1, env_list);
		error_handler("export", cmd, "not a valid identifier\n");
		return (FALSE);
	}
	return (TRUE);
}

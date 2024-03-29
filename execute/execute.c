/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:59:27 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/27 07:46:45 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	execute(t_list *head, t_env *env_list)
{
	char	*cmd;

	cmd = head->content;
	if (ft_strncmp(cmd, "exit", 5) == 0)
		ft_exit(head, env_list);
	else if (ft_strncmp(cmd, "pwd", 4) == 0)
		ft_pwd(head, env_list);
	else if (ft_strncmp(cmd, "cd", 3) == 0)
		ft_cd(head, env_list);
	else if (ft_strncmp(cmd, "env", 4) == 0)
		ft_env(head, env_list);
	else if (ft_strncmp(cmd, "unset", 6) == 0)
		ft_unset(head, env_list);
	else if (ft_strncmp(cmd, "export", 7) == 0)
		ft_export(head, env_list);
	else if (ft_strncmp(cmd, "echo", 5) == 0)
		ft_echo(head);
	else
		execute_else(head);
}

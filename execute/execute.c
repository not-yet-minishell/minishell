/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:59:27 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/27 02:20:11 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "../parse/parse_env.h"

int	execute(t_list *head, t_env env_list)
{
	char	*cmd;

	cmd = head->content;
	if (ft_strncmp(cmd, "exit", 5) == 0)
		ft_exit(head);
}

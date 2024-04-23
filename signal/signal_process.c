/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:38:06 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 14:16:38 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "minsignal.h"

void	signal_child_process(t_fd *fd_info, t_list *head, t_list *env)
{
	if (fd_info->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		start_command(head, fd_info, env);
	}
}

void	signal_original(void)
{
	signal(SIGINT, signalhandler);
	signal(SIGQUIT, SIG_IGN);
}

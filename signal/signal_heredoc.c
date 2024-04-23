/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:36:53 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 11:39:04 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "minsignal.h"

void signal_heredoc(void)
{
	if (g_signal == SIGINT)
	{
		close(STDIN_FILENO);
	}
	ft_putstr_fd("\e7", 1);
}

int	is_lead_line_null(char *read_line)
{
	if (read_line == NULL)
	{
		do_sigterm();
		return (1);
	}
	return (0);
}

int	is_singint_in_herdoc(int in_fd, t_list *envp)
{
	if (g_signal == SIGINT)
	{
		g_signal = 0;
		dup2(in_fd, STDIN_FILENO);
		((t_builtin *)envp->content)->exit_num = 1;
		return (1);
	}
	return (0);
}
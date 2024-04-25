/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_heredoc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:36:53 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 12:52:54 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "minsignal_bonus.h"
#include <readline/readline.h>

void	signal_heredoc(void)
{
	if (g_signal == SIGINT)
	{
		close(STDIN_FILENO);
		rl_event_hook = NULL;
	}
	ft_putstr_fd("\e7", 1);
}

int	is_lead_line_null(char *read_line)
{
	if (read_line == NULL)
	{
		ft_putstr_fd("\e8\e[B\e[A", 1);
		return (1);
	}
	return (0);
}

int	is_singint_in_herdoc(int in_fd, t_list *envp, int *signal_flag)
{
	if (g_signal == SIGINT)
	{
		g_signal = 0;
		dup2(in_fd, STDIN_FILENO);
		((t_builtin *)envp->content)->exit_num = 1;
		*signal_flag = SIGINT;
		return (1);
	}
	return (0);
}

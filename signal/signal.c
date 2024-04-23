/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:50:38 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 14:16:14 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsignal.h"
#include "../minishell.h"
#include <readline/readline.h>
#include <termios.h>

volatile sig_atomic_t	g_signal = 0;
static void				do_sigint(void);

void	signalinit(void)
{
	rl_event_hook = (rl_hook_func_t *)signal_readline;
	rl_catch_signals = 0;
	signal(SIGINT, signalhandler);
	signal(SIGQUIT, SIG_IGN);
}

void	signalhandler(int signum)
{
	g_signal = signum;
}

void	signal_readline(void)
{
	if (g_signal == SIGINT)
	{
		do_sigint();
		g_signal = -1;
	}
	ft_putstr_fd("\e7", 1);
}

static void	do_sigint(void)
{
	ft_putstr_fd("\n", 2);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	do_sigterm(void)
{
	ft_putstr_fd("\e8\e[B\e[A", 1);
	ft_putstr_fd("exit\n", 1);
}

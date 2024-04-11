/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:50:38 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/11 11:16:37 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsignal.h"
#include "../minishell.h"
#include <readline/readline.h>
#include <termios.h>

volatile sig_atomic_t	g_signal = 0;
static void				signalhadnler(int signum);
static void				signal_readline(void);
static void				do_sigint(void);

void	signalinit(void)
{
	rl_event_hook = (rl_hook_func_t *)signal_readline;
	set_terminal_print_off();
	signal(SIGINT, signalhadnler);
	signal(SIGQUIT, SIG_IGN);
}

static void	signalhadnler(int signum)
{
	g_signal = signum;
}

static void	signal_readline(void)
{
	if (g_signal == SIGINT)
	{
		set_terminal_print_off();
		do_sigint();
		g_signal = 0;
	}
	if (g_signal == SIGQUIT)
	{
		signal(SIGQUIT, SIG_IGN);
		g_signal = 0;
	}
}

static void	do_sigint(void)
{
	ft_putstr_fd("\n", 2);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	set_terminal_print_off(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

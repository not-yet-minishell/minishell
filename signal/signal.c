/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:50:38 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/22 19:06:50 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsignal.h"
#include "../minishell.h"
#include <readline/readline.h>
#include <termios.h>

volatile sig_atomic_t	g_signal = 0;
static void				signalhandler(int signum);
static void				do_sigint();

void	signalinit(void)
{
	rl_event_hook = (rl_hook_func_t *)signal_readline;
	rl_catch_signals = 0;
	//set_terminal_print_off();
	signal(SIGINT, signalhandler);
	//signal(SIGINT, do_sigint);
	signal(SIGQUIT, SIG_IGN);
}

static void	signalhandler(int signum)
{
	g_signal = signum;
}

void signal_heredoc(void)
{
	if (g_signal == SIGINT)
	{
		close(STDIN_FILENO);
		//rl_event_hook = NULL;
	}
}

void	signal_readline(void)
{
	if (g_signal == SIGINT)
	{
		//set_terminal_print_off();
		do_sigint();
		//rl_event_hook = NULL;
		g_signal = -1;
	}
	// if (g_signal == SIGQUIT)
	// {
	// 	signal(SIGQUIT, SIG_IGN);
	// 	g_signal = 0;
	// }
}

static void	do_sigint()
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

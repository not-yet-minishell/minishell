/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsignal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:07:43 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 13:25:40 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINSIGNAL_H
# define MINSIGNAL_H
# include <signal.h>
# include "../minishell.h"

extern volatile sig_atomic_t	g_signal;
void	signalinit(void);
void	set_terminal_print_off(void);
void	signal_heredoc(void);
void	signal_readline(void);
void	signalhandler(int signum);
void	do_sigterm(void);
int		is_lead_line_null(char *read_line);
int	is_singint_in_herdoc(int in_fd, t_list *envp, int *signal_flag);
void	signal_child_process(t_fd *fd_info, t_list *head, t_list *env);
void	signal_original(void);
#endif

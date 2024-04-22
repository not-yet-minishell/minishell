/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsignal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:07:43 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/22 17:15:29 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINSIGNAL_H
# define MINSIGNAL_H
# include <signal.h>

extern volatile sig_atomic_t	g_signal;
void	signalinit(void);
void	set_terminal_print_off(void);
void signal_heredoc(void);
void	signal_readline(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:05:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/19 11:03:36 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "parse/parse_list.h"
# include "parse/parse_env.h"
# include "printf/ft_printf.h"
# include "parse/parse_env.h"
# include "parse/parse_list.h"
# include "parse/parse.h"
# include "parse/parse_test.h"
# include "parse/wildcard.h"
# include "pipe/pipex.h"
# include "execute_builtin/execute_builtin.h"
# include "get_next_line/get_next_line_bonus.h"

void	error_handler(char *cmd_name, char *option_name, char *msg);
#endif
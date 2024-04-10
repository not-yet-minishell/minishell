/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:05:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/09 13:00:13 by yeoshin          ###   ########.fr       */
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
# include "pipe/pipex.h"
# include "execute_builtin/execute_builtin.h"

void	error_handler(char *cmd_name, char *option_name, char *msg);

//# include "pipe/pipex.h"
//# include "execute_builtin/execute_builtin.h"
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:05:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/24 10:28:08 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "ast/cmd_tree.h"
# include "extends/extends.h"
# include "printf/ft_printf.h"
# include "parse/parse.h"
# include "parse/parse_test.h"
# include "wildcard/wildcard.h"
# include "pipe/pipex.h"
# include "execute_builtin/execute_builtin.h"
# include "get_next_line/get_next_line_bonus.h"

void	error_handler(char *cmd_name, char *option_name, char *msg);
#endif
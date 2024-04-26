/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:05:52 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/26 15:51:48 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "parse/parse.h"
# include "ast/cmd_tree.h"
# include "extends/extends.h"
# include "wildcard/wildcard.h"
# include "execute_builtin/execute_builtin.h"

void	error_handler(char *cmd_name, char *option_name, char *msg);
int		main(int argc, char *argv[], char **envp);

#endif
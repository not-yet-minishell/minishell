/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:50:30 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 13:50:32 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include "../libft/libft.h"
# include "parse/parse_bonus.h"
# include "ast/cmd_tree_bonus.h"
# include "extends/extends_bonus.h"
# include "wildcard/wildcard_bonus.h"
# include "execute_builtin/execute_builtin_bonus.h"

void	error_handler(char *cmd_name, char *option_name, char *msg);
int		main(int argc, char *argv[], char **envp);

#endif
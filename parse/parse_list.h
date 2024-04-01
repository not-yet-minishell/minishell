/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:34:23 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/01 16:21:16 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LIST_H
# define PARSE_LIST_H
# include "../minishell.h"

typedef enum e_rd_type {
	RD_IN = 1,
	RD_HEREDOC,
	RD_OUT,
	RD_APPEND
}	t_rd_type;

typedef struct s_rd_node {
	int		rd_type;
	char	*filename;
}	t_rd_node;

typedef struct s_cmd_node {
	t_list	*rd_list;
	char	*exe_cmd;
}	t_cmd_node;

#endif
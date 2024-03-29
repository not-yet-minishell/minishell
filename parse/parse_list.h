/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:34:23 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/29 19:13:26 by soljeong         ###   ########.fr       */
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

typedef struct	s_rd_node {
	int		rd_type;
	char	*filename;
}	t_rd_node;

typedef struct	s_exe_node {
	char	*word;
}	t_exe_node;

typedef struct	s_cmd_node {
	t_list	*rd_list;
	t_list	*exe_list;
}	t_cmd_node;

#endif
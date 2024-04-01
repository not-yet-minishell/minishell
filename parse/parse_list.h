/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:34:23 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/01 09:42:16 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LIST_H
# define PARSE_LIST_H
# include "../minishell.h"

typedef struct s_rd_node {
	int		rd_type;
	char	*filename;
}	t_rd_node;

typedef struct s_exe_node {
	char	*word;
}	t_exe_node;

typedef struct s_cmd_node {
	t_list	*rd_list;
	t_list	*exe_list;
}	t_cmd_node;

#endif
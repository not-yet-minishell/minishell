/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:34:23 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/01 17:15:57 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LIST_H
# define PARSE_LIST_H

# include "../minishell.h"

typedef struct s_rd_node {
	int		rd_type;
	char	*filename;
}	t_rd_node;

typedef struct s_cmd_node {
	t_list	*rd_list;
	t_list	*cmd_list;
}	t_cmd_node;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:34:23 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/29 17:43:30 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	struct s_rd_node	*rd_list;
	struct s_exe_node	*exe_list;
}	t_cmd_node;
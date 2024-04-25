/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:34:23 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 11:41:38 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_TREE_H
# define CMD_TREE_H

# include "../../libft/libft.h"
# include "../parse/parse.h"
# include "../pipe/pipex.h"

typedef struct s_cmd_node {
	t_list	*rd_list;
	t_list	*cmd_list;
}	t_cmd_node;

void		tree_status_list(t_tree *tree, int *flag, int exit_num);
void		tree_status_pipeline(t_tree *tree, int flag, \
t_list *envp, int *exit_num);
t_rd_node	*new_rd_node(int rd_type, char *filename);
t_cmd_node	*new_cmd_node(t_list *rd_list, t_list *cmd_list);
int			divide_flag(int type, int exit_num);
t_list		*make_pipelist(t_tree *tree);
void		free_pipe_list(t_list *pipelist);
void		free_cmd_list(t_list *cmd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:43:30 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/23 13:08:21 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "../minishell.h"

typedef struct s_fd
{
	int		fds[2];
	int		pid;
	int		temp_fd;
}	t_fd;

void	execute(t_list *node, t_list *env);
int		wait_process(t_fd *fd_info, int fork_count);
void	start_command(t_list *node, t_fd *fd_info, t_list *env);
int		redirect(t_rd_node *node);
int		start_process(t_list *head, t_list *env);
char	**find_path_to_array(t_list *env);
char	**make_list_to_array(t_list *node);
t_list	*delete_and_next_node(t_list *node);
t_list	*free_and_next_rd(t_list *rd_node);
int		one_process(t_list *node, t_list *env);
char	**make_env_array(t_list *env);
int		herdoc_tree_init(t_tree *tree, t_list *envp);

#endif
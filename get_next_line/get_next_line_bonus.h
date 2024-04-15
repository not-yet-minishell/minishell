/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:57:47 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/16 15:42:48 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	char			*content;
	int				fd_num;
	struct s_node	*next;
	int				buf_size;
	int				str_len;
}	t_node;

char	*get_next_line(int fd);
char	*substr(t_node *node, int idx_n);
t_node	*find_fd(int fd, t_node **head);
void	*all_free(t_node **head);
char	*delete_node(t_node **head, int fd, char *ret);
int		get_read(t_node *node, int fd);
void	str_join(t_node *node, char *str2, int read_len);
int		find_n(char *str, int str_len);
t_node	*new_node(t_node **head, int fd);
int		manage_buf(t_node *node, char *str, int read_len);

#endif
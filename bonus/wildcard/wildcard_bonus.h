/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:26:48 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 13:26:50 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_BONUS_H
# define WILDCARD_BONUS_H
# include "../../libft/libft.h"
# include <histedit.h>
# include <dirent.h>

void	wildcard(t_list **cmd_list);
int		is_match(char *str, char *pattern);
void	wildcard_cmd(t_list **cmd_list);
void	wildcard_rd(t_list **rd_list);
int		has_wildcard(char *str);
int		is_wildcard_dirtory(char *str);
char	*delete_dir_flag(char *str);
t_list	*find_wildcard(char *str, char *front);
void	make_wildcard_list(t_list **wildlist, \
struct dirent *entry, char *front);
char	*make_new_front(char *str);
char	*make_new_str(char *str);
t_list	*wildcard_file_list(char *filename);
#endif
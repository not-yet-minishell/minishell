/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:58:27 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/19 11:16:13 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H
# define WILDCARD_H
# include "../libft/libft.h"
# include <histedit.h>
# include <dirent.h>

void	wildcard(t_list **cmd_list);
int		is_match(char *str, char *pattern);
void	wildcard_cmd(t_list **cmd_list);
void	wildcard_rd(t_list **rd_list);
int		has_wildcard(char *str);
int		is_wildcard_dirtory(char *str);
char	*delete_dir_flag(char *str);
t_list	*find_wildcard(char *str);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:56:57 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/26 19:35:04 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define FALSE -1
# define TRUE 1

# include <libft/libft.h>
# include <sys/errno.h>

void	free_list(t_list *head);
void	ft_exit(t_list *head);
void	error_handler(char *cmd_name, char *option_name, char *msg);
int		execute(t_list *head);

#endif
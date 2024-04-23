/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:34:08 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 12:36:10 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_and_closing(char *read_line, char *limiter, int in_fd, int fd)
{
	free(read_line);
	free(limiter);
	close(in_fd);
	close(fd);
}

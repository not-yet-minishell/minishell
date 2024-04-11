/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:56:12 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/09 11:22:49 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	unlink_heredoc(void);

int	wait_process(t_fd *fd_info, int fork_count)
{
	int		status;
	int		ret;

	ret = 0;
	status = 0;
	while (fork_count-- > 0)
	{
		if (wait(&status) == fd_info->pid)
		{
			if (WIFEXITED(status))
				ret = WEXITSTATUS(status);
		}
	}
	unlink_heredoc();
	return (ret);
}

static void	unlink_heredoc(void)
{}

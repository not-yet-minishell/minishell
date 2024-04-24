/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:56:12 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/24 09:29:44 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			{
				ret = WEXITSTATUS(status);
			}
			if (WIFSIGNALED(status))
			{
				ret = WTERMSIG(status);
				if (ret == SIGINT)
					ft_putstr_fd("\n", 1);
				else if (ret == SIGQUIT)
					ft_putstr_fd("Quit: 3\n", 1);
				ret += 128;
			}
		}
	}
	return (ret);
}

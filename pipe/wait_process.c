/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:56:12 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/18 17:51:02 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//static void	unlink_heredoc(int *heredoc_count);

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
	//unlink_heredoc(heredoc_count);
	return (ret);
}

//static void	unlink_heredoc(int *heredoc_count)
//{
//	char	*filename;
//	char	*num;

//	while ((*heredoc_count)-- > 0)
//	{
//		num = ft_itoa(*heredoc_count);
//		filename = ft_strjoin("/tmp/heredoc", num, '\0');
//		if (access(filename, F_OK) == 0)
//			unlink(filename);
//		free(num);
//		free(filename);
//	}
//}

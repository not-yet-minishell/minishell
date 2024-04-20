/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:56:12 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/20 17:25:30 by yeoshin          ###   ########.fr       */
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
			// 여기서 시그널을 중단시켜야하나///?
			if (WIFEXITED(status))
			{
				ret = WEXITSTATUS(status);
			}
			//signal 로 끝났다면? 매크로로 체크
			// w sigterm으로 어떤시그널로 끝났는지 체크
			// ret = 128 + sigterm ;
			// ^C도 찌곡...
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

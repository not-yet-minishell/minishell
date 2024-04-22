/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:42:14 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/22 19:12:16 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../signal/minsignal.h"
#include <readline/readline.h>

static int	open_heredoc(char *filename);
static void	start_read(char *lim, int fd, t_list *envp);
static char	*make_limiter(char *lim);
static char	*change_env(char *str, t_list *env);

char	*heredoc(char *lim, int *heredoc_count, t_list *envp)
{
	char	*filename;
	char	*num;
	int		fd;

	num = ft_itoa((*heredoc_count));
	filename = ft_strjoin("/tmp/heredoc", num, '\0');
	fd = open_heredoc(filename);
	start_read(lim, fd, envp);
	return (filename);
}

static int	open_heredoc(char *filename)
{
	int		fd;

	fd = open(filename, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		error_handler("here_doc", NULL, NULL);
	return (fd);
}

static void	start_read(char *lim, int fd, t_list *envp)
{
	char	*read_line;
	int		limiter_len;
	char	*limiter;
	int		in_fd;

	limiter = make_limiter(lim);
	limiter_len = ft_strlen(lim);
	rl_event_hook = (rl_hook_func_t *)signal_heredoc;
	in_fd = dup(STDIN_FILENO);
	while (1)
	{
		read_line = readline("> ");
		if (g_signal == SIGINT)
		{
			g_signal = 0;
			dup2(in_fd, STDIN_FILENO);
			((t_builtin *)envp->content)->exit_num = 1;
			break;
		}
		if (read_line == NULL)
		{
			ft_putstr_fd("\033[1A", 1); // 현재 커서의 위치를 한칸 위로 올려줌
			ft_putstr_fd("\033[2C", 1); // 현재 커서의 위치를 11번째칸으로 이동
			break ;
		}
		if (ft_strncmp(limiter, read_line, limiter_len) == 0)
			break ;
		read_line = change_env(read_line, envp);
		ft_putendl_fd(read_line, fd);
		free(read_line);
	}
	rl_event_hook = (rl_hook_func_t *)signal_readline;
	free(read_line);
	free(limiter);
	close(in_fd);
	close(fd);
}

static char	*change_env(char *str, t_list *env)
{
	int		idx;
	int		start;
	char	*new;
	char	*temp;

	idx = 0;
	start = 0;
	new = ft_strdup("\0");
	while (str[idx])
	{
		if (str[idx] == '$' && (str[idx + 1] != '\0' || str[idx + 1] != ' '))
		{
			str_divide_join(&new, str, start, idx);
			temp = extends_find_env(str, &idx, env);
			if (temp != NULL)
				str_temp_join(&new, temp);
			start = idx;
		}
		else
			idx++;
	}
	str_divide_join(&new, str, start, idx);
	free(str);
	return (new);
}

static char	*make_limiter(char *lim)
{
	char	*ret;
	int		len;

	len = ft_strlen(lim);
	ret = malloc(len + 2);
	while (len-- > 0)
		ret[len] = lim[len];
	len = ft_strlen(lim);
	ret[len] = '\n';
	ret[len + 1] = '\0';
	return (ret);
}

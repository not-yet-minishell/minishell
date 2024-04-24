/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:42:14 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/23 17:40:39 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../signal/minsignal.h"
#include <readline/readline.h>

static int	open_heredoc(char *filename);
static void	start_read(char *lim, int fd, t_list *envp, int *signal_flag);
static char	*make_limiter(char *lim, int *flag);
static char	*change_env(char *str, t_list *env);

char	*heredoc(char *lim, int *heredoc_count, t_list *envp, int *signal_flag)
{
	char	*filename;
	char	*num;
	int		fd;

	num = ft_itoa((*heredoc_count));
	filename = ft_strjoin("/tmp/heredoc", num, '\0');
	fd = open_heredoc(filename);
	start_read(lim, fd, envp, signal_flag);
	free(num);
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

static void	start_read(char *lim, int fd, t_list *envp, int *signal_flag)
{
	char	*read_line;
	int		limiter_len;
	char	*limiter;
	int		flag;
	int		in_fd;

	flag = 0;
	limiter = make_limiter(lim, &flag);
	limiter_len = ft_strlen(lim);
	//rl_event_hook = (rl_hook_func_t *)signal_heredoc;
	in_fd = dup(STDIN_FILENO);
	while (1)
	{
		read_line = readline("> ");
		if (is_singint_in_herdoc(in_fd, envp, signal_flag))
			break ;
		if (is_lead_line_null(read_line))
			break ;
		if (ft_strncmp(limiter, read_line, limiter_len + 1) == 0)
			break ;
		if (flag != 1)
			read_line = change_env(read_line, envp);
		write(fd, read_line, ft_strlen(read_line));
		free(read_line);
	}
	//rl_event_hook = (rl_hook_func_t *)signal_readline;
	free_and_closing(read_line, limiter, in_fd, fd);
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

static char	*make_limiter(char *lim, int *flag)
{
	char	*ret;
	int		len;

	lim = change_str_heredoc(lim, flag);
	len = ft_strlen(lim);
	ret = malloc(len + 2);
	while (len-- > 0)
		ret[len] = lim[len];
	len = ft_strlen(lim);
	//ret[len] = '\n';
	ret[len] = '\0';
	return (ret);
}

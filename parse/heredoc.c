/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:42:14 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/18 18:54:39 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	open_heredoc(char *filename);
static void	start_read(char *lim, int fd, t_list *envp);
static char	*make_limiter(char *lim);

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

	limiter = make_limiter(lim);
	limiter_len = ft_strlen(lim);
	while (1)
	{
		read_line = get_next_line(STDIN_FILENO);
		if (read_line == NULL)
			break ;
		if (ft_strncmp(limiter, read_line, limiter_len + 1) == 0)
			break ;
		read_line = change_env(read_line, envp);
		write(fd, read_line, ft_strlen(read_line));
		free(read_line);
	}
	free(read_line);
	free(limiter);
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
		if (str[idx] == '$')
		{
			str_divide_join(&new, str, start, idx);
			temp = check_and_change_str(str, &idx, env);
			if (temp != NULL)
				str_temp_join(&new, temp);
			start = idx;
		}
		else
			idx++;
	}
	str_divide_join(&new, str, start, idx);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:57:34 by yeoshin           #+#    #+#             */
/*   Updated: 2024/02/16 15:41:57 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_node	*head;
	t_node			*node;
	char			*ret;

	node = find_fd(fd, &head);
	if (node == NULL)
		node = new_node(&head, fd);
	if (node == NULL || BUFFER_SIZE <= 0)
		return (all_free(&head));
	if (find_n(node->content, node->str_len) == -1)
	{
		if (get_read(node, fd) == 0)
			return (delete_node(&head, fd, NULL));
	}
	if (find_n(node->content, node->str_len) == -1)
	{
		ret = substr(node, node->str_len - 1);
		return (delete_node(&head, fd, ret));
	}
	else
		ret = substr(node, find_n(node->content, node->str_len));
	if (ret == NULL)
		return (delete_node(&head, fd, ret));
	return (ret);
}

int	get_read(t_node *node, int fd)
{
	char		*buf;
	ssize_t		read_len;

	buf = (char *)malloc(BUFFER_SIZE);
	if (buf == NULL)
		return (0);
	while (find_n(node->content, node->str_len) == -1)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0 || manage_buf(node, buf, read_len) == -1)
		{
			free(buf);
			return (0);
		}
		if (read_len == 0)
		{
			free(buf);
			return (1);
		}
	}
	free(buf);
	return (1);
}

char	*substr(t_node *node, int idx_n)
{
	char	*ret_str;
	int		idx;

	idx = -1;
	if (node->str_len == 0)
		return (NULL);
	ret_str = (char *)malloc(idx_n + 2);
	if (ret_str == NULL)
		return (NULL);
	while (++idx <= idx_n)
		ret_str[idx] = node->content[idx];
	ret_str[idx_n + 1] = '\0';
	idx = 0;
	while (++idx_n < node->str_len)
		node->content[idx++] = node->content[idx_n];
	node->str_len = idx;
	return (ret_str);
}

t_node	*find_fd(int fd, t_node **head)
{
	t_node	*now;

	if (fd < 0)
		return (NULL);
	now = *head;
	while (now != NULL)
	{
		if (now->fd_num == fd)
			return (now);
		now = now->next;
	}
	return (NULL);
}

int	manage_buf(t_node *node, char *str, int read_len)
{
	char	*big_buf;
	int		idx;

	idx = -1;
	if (read_len < 0)
		return (-1);
	if (node->str_len + read_len <= node->buf_size)
	{	
		str_join(node, str, read_len);
		return (1);
	}
	else
	{
		node->buf_size *= 2;
		big_buf = (char *)malloc(node->buf_size);
		if (big_buf == NULL)
			return (-1);
		while (++idx < node->str_len)
			big_buf[idx] = node->content[idx];
		free(node->content);
		node->content = big_buf;
		str_join(node, str, read_len);
		return (1);
	}
}

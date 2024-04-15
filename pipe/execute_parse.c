/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:58:11 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/11 17:26:54 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path_to_array(t_list *env)
{
	char	*path;

	path = NULL;
	while (env != NULL)
	{
		if (ft_strncmp(((t_env *)env->content)->key, "PATH", 5) == 0)
		{
			path = ((t_env *)env->content)->value;
			break ;
		}
		env = env->next;
	}
	if (path == NULL)
		path = "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:.";
	return (ft_split(path, ':'));
}

char	**make_list_to_array(t_list *node)
{
	char	**ret;
	int		list_len;
	t_list	*pre;
	int		idx;

	idx = 0;
	list_len = ft_lstsize(node);
	ret = (char **)ft_malloc(sizeof(char *) * (list_len + 1));
	while (node != NULL)
	{
		//printf("node content : %s\n", (char *)node->content);
		ret[idx] = (char *)node->content;
		//printf("ret[idx] : %s\n", ret[idx]);
		pre = node;
		node = node->next;
		idx++;
	}
	ret[idx] = NULL;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:59:34 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/29 20:49:49 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(t_list *node)
{
	char	**exe;

	exe = make_list_to_array(node);

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
		ret[idx] = node->content;
		pre = node;
		node = node->next;
		free(pre->content);
		free(pre);
		idx++;
	}
	ret[idx] = NULL;
	return (ret);
}

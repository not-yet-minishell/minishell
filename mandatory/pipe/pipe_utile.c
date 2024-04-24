/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:57:40 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/22 08:58:29 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*delete_and_next_node(t_list *node)
{
	t_list			*temp;
	t_cmd_node		*cmd_node;
	t_list			*rd_list;
	t_list			*temp_rd_list;

	temp = node;
	node = node->next;
	cmd_node = (t_cmd_node *)temp->content;
	rd_list = cmd_node->rd_list;
	while (rd_list != NULL)
	{
		temp_rd_list = rd_list;
		rd_list = rd_list->next;
		free(((t_rd_node *)temp_rd_list->content)->filename);
		free(temp_rd_list->content);
		free(temp_rd_list);
	}
	free_cmd_list(cmd_node->cmd_list);
	free(cmd_node);
	free(temp);
	return (node);
}

char	**make_env_array(t_list *env_list)
{
	t_env	*content;
	char	**env_array;
	char	*env;
	int		idx;

	idx = 0;
	env_list = env_list->next;
	env_array = malloc(sizeof(char *) * (ft_lstsize(env_list) + 1));
	while (env_list != NULL)
	{
		content = env_list->content;
		env = ft_strjoin(content->key, content->value, '=');
		env_array[idx] = env;
		idx++;
		env_list = env_list->next;
	}
	env_array[idx] = NULL;
	return (env_array);
}

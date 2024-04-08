/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:57:50 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/08 20:25:17 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
	}
}

void	change_exit_number(int exit_num, t_list *env_list)
{
	t_builtin	*content;

	content = env_list->content;
	content->exit_num = &exit_num;
}

void	delete_env_node(t_list *pre, t_list *current)
{
	t_list	*next;
	t_env	*content;

	next = current->next;
	content = current->content;
	free(content->key);
	free(content->value);
	free(content);
	free(current);
	pre->next = next;
}

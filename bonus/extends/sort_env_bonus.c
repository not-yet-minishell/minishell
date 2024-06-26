/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:29:18 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 12:50:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

static t_list	*list_delete(t_list *prev, t_list *curr);
static void		select_sort_selectsmall(t_list **head, t_list **new_list);
static void		list_delete_and_add(t_list *small, t_list *small_prev, \
t_list **new_list, t_list **head);

t_list	*select_sort(t_list *env_list)
{
	t_list	*new_list;
	t_list	*head;

	head = (env_list)->next;
	new_list = NULL;
	while (head)
		select_sort_selectsmall(&head, &new_list);
	env_list->next = NULL;
	ft_lstadd_front(&new_list, env_list);
	return (new_list);
}

static void	select_sort_selectsmall(t_list **head, t_list **new_list)
{
	t_list	*curr;
	t_list	*small_prev;
	t_list	*small;
	t_list	*prev;

	prev = (*head);
	curr = (*head)->next;
	small = *head;
	small_prev = NULL;
	while (curr)
	{
		if (ft_strncmp(((t_env *)small->content)->key, \
		((t_env *)curr->content)->key, \
		ft_strlen(((t_env *)curr->content)->key) + 1) > 0)
		{
			small = curr;
			small_prev = prev;
		}
		prev = curr;
		curr = curr->next;
	}
	list_delete_and_add(small, small_prev, new_list, head);
}

static void	list_delete_and_add(t_list *small, t_list *small_prev, \
t_list **new_list, t_list **head)
{
	t_list	*temp;

	if (small == (*head))
	{
		temp = (*head)->next;
		(*head)->next = NULL;
		ft_lstadd_back(new_list, (*head));
		(*head) = temp;
	}
	else
		ft_lstadd_back(new_list, list_delete(small_prev, small));
}

static t_list	*list_delete(t_list *prev, t_list *curr)
{
	if (prev && curr->next)
		prev->next = curr->next;
	if (prev && curr && curr->next == NULL)
		prev->next = NULL;
	curr->next = NULL;
	return (curr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:29:18 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/04 20:32:20 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s1, s2, s2len, -가 나오면 s1이 제일 작은것임

#include "../minishell.h"

// 선택정렬로 구현... 제일 작은 친구 앞에 넣는 리스트 만들기
//static void lst_chage(t_list *prev, t_list *list1,t_list *list2);
t_list *list_delete(t_list *prev, t_list *curr);
void	print_env(t_list *env_list);
t_list	*select_sort(t_list *env_list)
{
	 t_list	*new_list;
	t_list	*head;
	t_list	*prev;
	t_list	*small_prev;
	t_list	*curr;
	t_list	*small;

	head = (env_list)->next;
	curr = head->next;
	small = head;
	small_prev = NULL;
	prev = NULL;
	new_list = NULL;
	while(head)
	{
		printf("%s\n",((t_env *)head->content)->key);
		printf("%d\n",ft_lstsize(head));
		print_env(env_list);
		curr = head->next;
		small = head;
		small_prev = NULL;
		//prev = NULL;
		while (curr)
		{
			//printf("curr : %s\n", ((t_env *)curr->content)->key);
			if (ft_strncmp(((t_env *)small->content)->key,((t_env *)curr->content)->key, ft_strlen(((t_env *)curr->content)->key)) > 0)
			{
				//printf("small :%s curr : %s\n",((t_env *)small->content)->key,((t_env *)curr->content)->key);
				small = curr;
				small_prev = prev;
			}
			prev = curr;
			curr = curr->next;
		}
		if (new_list == NULL)
		{
			new_list = list_delete(small_prev,small);
			//t_list *list_delete(t_list *prev, t_list *curr)
		}else
		{
			if (small_prev == NULL)
				head = head->next;
			ft_lstadd_back(&new_list,list_delete(small_prev,small));
		}
		//printf("%s\n",((t_env *)small->content)->key);
	}
	return new_list;
}

void bubble_sort(t_list *env_list)
{
	t_list	*env1;
	t_list	*env2;
	t_list	*prev;
	char	*key1;
	char	*key2;

	prev = NULL;
	env1 = env_list->next;
	while (env1)
	{
		env2 = env1->next;
		while (env2)
		{
			key1 = ((t_env *)env1->content)->key;
			key2 = ((t_env *)env2->content)->key;
			printf("key1 : %s key2 : %s\n",key1,key2);
			// if (ft_strncmp(key1,key2, ft_strlen(key2)) > 0)
			// 	lst_chage(prev, env1, env2);
			env2 = env2->next;
		}
		prev = env1;
		env1 = env1->next;
	}
}

t_list *list_delete(t_list *prev, t_list *curr)
{
	//if (curr == NULL)
	//	return NULL;
	if (prev == NULL)
	{
		curr->next = NULL;
		return curr;
	}
	if (prev && curr->next)
		prev->next = curr->next;
	if (curr->next == NULL)
	{
		prev->next = NULL;
		return curr;
	}
	curr->next = NULL;
	return curr;
}

void lst_chage(t_list *prev, t_list *list1,t_list *list2)
{
	if (list1 == NULL || list2 == NULL)
		return ;
	if (prev != NULL)
		(prev)->next = list2;
	(list1)->next = (list2)->next;
	(list2)->next = list1;
}
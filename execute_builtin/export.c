/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:53 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/08 20:26:01 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static t_list	*find_insert(t_list *env_list, char *key);
static void		print_export(t_list *env_list);
static void		add_envlist(t_list *env_list, t_list *new_node);
static t_env	*devide_key_value(char *env);

//따옴표 처리

void	export(char **cmd, t_list *env_list)
{
	char	*env;
	t_env	*content;
	t_list	*node;

	env = *(cmd + 1);
	cmd++;
	if (env == NULL)
	{
		print_export(env_list);
		change_exit_number(0, env_list);
		return ;
	}
	while (cmd != NULL)
	{
		env = *cmd;
		cmd++;
		content = divide_key_value(env);
		node = ft_lstnew(content);
		add_envlist(env_list, node);
	}
	change_exit_number(0, env_list);
}

static void	print_export(t_list *env_list)
{
	t_env	*content;

	env_list = env_list->next;
	while (env_list != NULL)
	{
		content = (t_env *)env_list->content;
		printf(1, "declare -x %s", content->key);
		if (content->value != NULL)
			printf(1, "=\"%s\"\n", content->value);
		else
			printf(1, "\n");
		env_list = env_list->next;
	}
}

static void	add_envlist(t_list *env_list, t_list *new_node)
{
	t_list	*temp;
	t_list	*pre;
	t_list	*back;

	env_list = env_list->next;
	if (env_list == NULL)
		env_list = new_node;
	else
	{
		pre = find_insert(env_list, ((t_env *)new_node->content)->key);
		if (pre == NULL)
		{
			new_node->next = env_list;
			env_list = new_node;
		}
		else
		{
			temp = pre->next;
			pre->next = new_node;
			new_node->next = temp;
		}
	}
}

static t_list	*find_insert(t_list *head, char *key)
{
	t_list	*pre;
	t_env	*content;
	t_list	*temp;
	t_list	*env_list;

	pre = head;
	env_list = head->next;
	while (env_list != NULL)
	{
		content = env_list->content;
		if (ft_strncmp(key, content->key, ft_strlen(key) + 1) == 0)
		{
			delete_env_node(pre, env_list);
			break ;
		}
		if (ft_strncmp(key, content->key, ft_strlen(key) + 1) < 0)
			break ;
		pre = env_list;
		env_list = env_list -> next;
	}
	return (pre);
}

static t_env	*devide_key_value(char *env)
{
	char	*key;
	char	*value;
	t_env	*content;
	int		idx;

	content = (t_env *)ft_malloc(sizeof(env));
	value = NULL;
	idx = 0;
	while (env[idx] && env[idx] != '=')
		idx++;
	key = ft_substr(env, 0, idx);
	value = ft_substr(env, idx + 1, ft_strlen(env) - idx - 1);
	content->key = key;
	content->value = value;
	return (content);
}

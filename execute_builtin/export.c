/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:53 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/11 11:10:03 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static t_list	*find_insert(t_list *env_list, char *key);
static void		print_export(t_list *env_list);
static void		add_envlist(t_list *env_list, t_list *new_node);
static t_env	*devide_key_value(char *env);

//따옴표 처리

void	ft_export(char **cmd, t_list *env_list)
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
	while (*cmd != NULL)
	{
		env = *cmd;
		cmd++;
		content = devide_key_value(env);
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
		ft_printf(1, "declare -x %s", content->key);
		if (content->value != NULL)
			ft_printf(1, "=\"%s\"\n", content->value);
		else
			ft_printf(1, "\n");
		env_list = env_list->next;
	}
}

static void	add_envlist(t_list *env_list, t_list *new_node)
{
	t_list	*temp;
	t_list	*pre;

	pre = env_list;
	env_list = env_list->next;
	if (env_list == NULL)
		pre->next = new_node;
	pre = find_insert(env_list, ((t_env *)new_node->content)->key);
	temp = pre->next;
	pre->next = new_node;
	new_node->next = temp;
}

static t_list	*find_insert(t_list *head, char *key)
{
	t_list	*pre;
	t_env	*content;
	t_list	*current;

	pre = head;
	current = head->next;
	while (current != NULL)
	{
		content = current->content;
		if (ft_strncmp(key, content->key, ft_strlen(key) + 1) == 0)
		{
			delete_env_node(pre, current);
			break ;
		}
		if (ft_strncmp(key, content->key, ft_strlen(key) + 1) < 0)
			break ;
		pre = current;
		current = current -> next;
	}
	return (pre);
}

static t_env	*devide_key_value(char *env)
{
	char	*key;
	char	*value;
	t_env	*content;
	int		idx;

	content = (t_env *)ft_malloc(sizeof(t_env));
	value = NULL;
	idx = 0;
	while (env[idx] != '\0' && env[idx] != '=')
		idx++;
	key = ft_substr(env, 0, idx);
	if (env[idx] == '\0')
		value = NULL;
	else if (env[idx] == '=' && env[idx + 1] == '\0')
		value = "\0";
	else
		value = ft_substr(env, idx + 1, ft_strlen(env) - idx - 1);
	content->key = key;
	content->value = value;
	return (content);
}

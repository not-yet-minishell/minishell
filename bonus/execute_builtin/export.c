/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:53 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 10:42:58 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static t_list	*find_insert(t_list *env_list, char *key);
static void		print_export(t_list *env_list);
static void		add_envlist(t_list *env_list, t_list *new_node);
static t_env	*devide_key_value(char *env);

void	ft_export(char **cmd, t_list *env_list)
{
	t_env	*content;
	t_list	*node;

	cmd++;
	change_exit_number(0, env_list);
	if (*cmd == NULL)
	{
		print_export(env_list);
		return ;
	}
	if (cmd[0][0] == '-' && cmd[0][1] != '-')
		return ;
	while (*cmd != NULL)
	{
		if (check_export_cmd(*cmd, env_list) == FALSE)
		{
			cmd++;
			continue ;
		}
		content = devide_key_value(*cmd);
		node = ft_lstnew(content);
		add_envlist(env_list, node);
		cmd++;
	}
}

static void	print_export(t_list *env_list)
{
	t_env	*content;

	env_list = env_list->next;
	while (env_list != NULL)
	{
		content = (t_env *)env_list->content;
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(content->key, STDOUT_FILENO);
		if (content->value != NULL)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(content->value, STDOUT_FILENO);
			ft_putendl_fd("\"", STDOUT_FILENO);
		}
		else
			ft_putstr_fd("\n", STDOUT_FILENO);
		env_list = env_list->next;
	}
}

static void	add_envlist(t_list *env_list, t_list *new_node)
{
	t_list	*temp;
	t_list	*pre;
	t_list	*current;

	pre = env_list;
	current = env_list->next;
	if (current == NULL)
	{
		pre->next = new_node;
		return ;
	}
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
		value = ft_strdup("\0");
	else
		value = ft_substr(env, idx + 1, ft_strlen(env) - idx - 1);
	content->key = key;
	content->value = value;
	return (content);
}

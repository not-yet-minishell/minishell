/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:59:48 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 15:28:50 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extends_bonus.h"

static char			*make_key(char *env, int *path_flag);
static char			*make_value(char *env);
static t_env		*init_content(char *env, int *path_flag);
static t_builtin	*init_head_content(void);

t_list	*parse_env(char *env[])
{
	t_env	*content;
	t_list	*env_node;
	t_list	*env_head;
	int		idx;
	int		path_flag;

	idx = 0;
	path_flag = 0;
	env_head = NULL;
	while (env[idx] != NULL)
	{
		content = init_content(env[idx], &path_flag);
		env_node = ft_lstnew(content);
		ft_lstadd_back(&env_head, env_node);
		idx++;
	}
	if (path_flag == 0)
		add_oldpwd(&env_head);
	find_and_add_path(&env_head);
	find_and_add_pwd(env_head);
	find_and_add_oldpwd(env_head);
	env_node = ft_lstnew(init_head_content());
	ft_lstadd_front(&env_head, env_node);
	return (select_sort(env_head));
}

static t_builtin	*init_head_content(void)
{
	t_builtin	*content;

	content = ft_malloc(sizeof(t_builtin));
	content->pwd = getenv("PWD");
	content->exit_num = 0;
	return (content);
}

static t_env	*init_content(char *env, int *path_flag)
{
	t_env	*content;

	content = ft_malloc(sizeof(t_env));
	content->key = NULL;
	content->value = NULL;
	content->key = make_key(env, path_flag);
	content->value = make_value(env);
	return (content);
}

static char	*make_key(char *env, int *path_flag)
{
	int		idx;
	int		len;
	char	*key;

	len = 0;
	idx = 0;
	while (env[len] && env[len] != '=')
		len++;
	key = (char *)ft_malloc(len + 2);
	while (idx < len)
	{
		key[idx] = env[idx];
		idx++;
	}
	key[idx] = '\0';
	if (ft_strncmp(key, "OLDPWD", 7) == 0)
		(*path_flag) = 1;
	return (key);
}

static char	*make_value(char *env)
{
	int		idx;
	int		value_idx;
	int		len;
	char	*value;

	idx = 0;
	value_idx = 0;
	len = ft_strlen(env);
	while (env[idx] && env[idx] != '=')
		idx++;
	if (env[idx] == '\0')
		return (ft_strdup(""));
	idx++;
	value = ft_malloc(len - idx + 1);
	while (idx < len)
	{
		value[value_idx] = env[idx];
		idx++;
		value_idx++;
	}
	value[value_idx] = '\0';
	return (value);
}

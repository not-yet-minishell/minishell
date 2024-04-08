/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:59:48 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/08 10:41:20 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_env.h"

static char		*make_key(char *env);
static char		*make_value(char *env);
static t_env	*init_content(char *env);

t_list	*parse_env(char *env[])
{
	t_env	*content;
	t_list	*env_node;
	t_list	*env_head;
	int		idx;
	int		*exit_num;

	idx = 0;
	env_head = NULL;
	while (env[idx] != NULL)
	{
		content = init_content(env[idx]);
		env_node = ft_lstnew(content);
		ft_lstadd_back(&env_head, env_node);
		idx++;
	}
	idx = 0;
	exit_num = &idx;
	env_node = ft_lstnew(exit_num);
	ft_lstadd_front(&env_head, env_node);
	return (env_head);
}

static t_env	*init_content(char *env)
{
	t_env	*content;

	content = ft_malloc(sizeof(t_env));
	content->key = make_key(env);
	content->value = make_value(env);
	return (content);
}

static char	*make_key(char *env)
{
	int		idx;
	int		len;
	char	*key;

	len = 0;
	idx = 0;
	while (env[len] != '=')
		len++;
	key = (char *)ft_malloc(len + 2);
	while (idx < len)
	{
		key[idx] = env[idx];
		idx++;
	}
	key[idx] = '\0';
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
	while (env[idx] != '=')
		idx++;
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

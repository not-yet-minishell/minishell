/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:59:48 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/27 02:38:05 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_env.h"

static char	*make_key(char *env);
static char	*make_value(char *env);

t_env	*parse_env(char *env[])
{
	t_env	*node;
	t_env	*pre;
	t_env	*head;
	int		idx;

	idx = 0;
	pre = NULL;
	while (env[idx] != NULL)
	{
		node = (t_env *)ft_malloc(sizeof(t_env));
		node->key = make_key(env[idx]);
		node->value = make_value(env[idx]);
		node->next = NULL;
		idx++;
		if (pre != NULL)
			pre->next = node;
		else
			head = node;
		pre = node;
	}
	return (head);
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
	idx++;
	key = (char *)ft_malloc(len + 2);
	while (idx <= len)
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
	int		len;
	char	*value;

	idx = 0;
	len = ft_strlen(env);
	while (env[idx] != '=')
		idx++;
	idx++;
	value = (char *)ft_malloc(len + 1);
	while (idx < len)
	{
		value[idx] = env[idx];
		idx++;
	}
	value[idx] = '\0';
	return (value);
}

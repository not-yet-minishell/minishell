/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extends_find_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:50:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/24 13:18:21 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*find_env_value(t_list *head, char *key);
static void	value_chage_whildcard(char **value);
static char	*key_has_specialchar(char *str, int *i);

char	*extends_find_env(char *str, int *i, t_list *env)
{
	int		env_start;
	char	*key;
	char	*value;

	value = NULL;
	(*i)++;
	if (str[*i] == '\?')
		extdns_find_exit_code(i, &value, env);
	else
	{
		env_start = *i;
		if (str[*i] >= '0' && str[*i] <= '9')
			return (extends_find_env_firstnum(str, i, &env_start));
		while (ft_isalnum((int)str[*i]))
			(*i)++;
		if (env_start == (*i))
			return (key_has_specialchar(str, i));
		key = ft_substr(str, env_start, (*i) - env_start);
		value = find_env_value(env, key);
		value_chage_whildcard(&value);
		env_start = *i;
		free(key);
	}
	return (value);
}

static char	*key_has_specialchar(char *str, int *i)
{
	if (str[(*i)] == '\0' || str[(*i)] == ' ')
		return (ft_strdup("$"));
	while (str[*i] && !ft_isalnum((int)str[*i]) \
	&& str[*i] != '\"' && str[*i] != '\'')
		(*i)++;
	return (ft_strdup(""));
}

static void	value_chage_whildcard(char **value)
{
	int	idx;

	idx = 0;
	while (*value && (*value)[idx])
	{
		if ((*value)[idx] == '*')
			(*value)[idx] = '\12';
		idx++;
	}
}

char	*chage_env_key_to_value(char *str, t_list *env)
{
	int		i;
	int		start;
	char	*new;
	char	*temp;

	i = 0;
	new = ft_strdup("\0");
	start = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			str_divide_join(&new, str, start, i);
			temp = extends_find_env(str, &i, env);
			str_temp_join(&new, temp);
			start = i;
		}
		else
			i++;
	}
	str_divide_join(&new, str, start, i);
	free(str);
	return (new);
}

static char	*find_env_value(t_list *head, char *key)
{
	t_list	*curr;
	t_env	*content;

	if (head == NULL || head->next == NULL)
		return (NULL);
	curr = head->next;
	while (curr != NULL)
	{
		content = curr->content;
		if (ft_strncmp(key, content->key, ft_strlen(key) + 1) == 0)
		{
			return (ft_strdup(content->value));
		}
		curr = curr->next;
	}
	return (NULL);
}

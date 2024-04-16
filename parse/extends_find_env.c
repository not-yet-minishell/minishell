/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extends_find_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:50:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/15 20:14:36 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_env_value(t_list *head, char *key);
char	*chage_env_key_to_value(char *str, t_list *env);
char	*find_exit_code(t_list *env);

char	*extends_find_env(char *str, int *i, t_list *env)
{
	int		env_start;
	char	*key;
	char	*value;

	value = NULL;
	(*i)++;
	if (str[*i] == '\?')
	{
		value = find_exit_code(env);
		(*i)++;
	}
	else
	{
		env_start = *i;
		while (ft_isalnum((int)str[*i]))
			(*i)++;
		key = ft_substr(str, env_start, (*i) - env_start);
		value = find_env_value(env, key);
		free(key);
	}
	return (value);
}

char	*find_exit_code(t_list *env)
{
	t_builtin	*content;
	char		*str;

	content = env->content;
	printf("%d\n",(content->exit_num));
	str = ft_itoa((content->exit_num));
	return (str);
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
			printf("%s\n",temp);
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

char	*find_env_value(t_list *head, char *key)
{
	t_list	*curr;
	t_env	*content;

	if (head == NULL || head->next == NULL)
		return (NULL);
	curr = head->next;
	while (curr != NULL)
	{
		content = curr->content;
		if (ft_strncmp(key, content->key, ft_strlen(key)) == 0)
		{
			return (ft_strdup(content->value));
		}
		curr = curr->next;
	}
	return (NULL);
}
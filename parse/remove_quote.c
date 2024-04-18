/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/18 11:32:11 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// #include "../libft/libft.h"
// #include "parse.h"

char	*remove_singlequote(char *str, int *i);
char	*remove_dobulequote(char *str, int *i, t_list *env);
char	*check_and_change_str(char *str, int *i, t_list *env);

char	*change_str(char *str, t_list *env)
{
	int		i;
	int		start;
	char	*new;
	char	*temp;

	i = 0;
	start = 0;
	new = ft_strdup("\0");
	while (str[i])
	{
		if (str[i] == '*')
		{
			str[i] = '\12';
			i++;
		}
		else if (str[i] == '\"' || str[i] == '\'' || str[i] == '$')
		{
			str_divide_join(&new, str, start, i);
			temp = check_and_change_str(str, &i, env);
			if (temp != NULL)
				str_temp_join(&new, temp);
			start = i;
		}
		else
			i++;
	}
	str_divide_join(&new, str, start, i);
	return (new);
}

char	*check_and_change_str(char *str, int *i, t_list *env)
{
	char	*temp;

	temp = NULL;
	if (str[*i] == '\"')
		temp = remove_dobulequote(str, i, env);
	else if (str[*i] == '\'')
		temp = remove_singlequote(str, i);
	else if (str[*i] == '$')
		temp = extends_find_env(str, i, env);
	return (temp);
}

char	*remove_dobulequote(char *str, int *i, t_list *env)
{
	char	*removed_str;
	int		start;

	(*i)++;
	start = (*i);
	while (str[*i])
	{
		if (str[*i] == '\"')
		{
			removed_str = ft_substr(str, start, (*i) - start);
			(*i)++;
			return (chage_env_key_to_value(removed_str, env));
		}
		(*i)++;
	}
	return (NULL);
}

char	*remove_singlequote(char *str, int *i)
{
	char	*removed_str;
	int		start;

	(*i)++;
	start = (*i);
	while (str[*i])
	{
		if (str[*i] == '\'')
		{
			removed_str = ft_substr(str, start, (*i) - start);
			(*i)++;
			return (removed_str);
		}
		(*i)++;
	}
	return (NULL);
}

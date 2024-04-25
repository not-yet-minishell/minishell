/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/24 10:37:41 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*remove_singlequote_heredoc(char *str, int *i);
static char	*remove_dobulequote_heredoc(char *str, int *i);
static char	*check_and_change_str(char *str, int *i);

char	*change_str_heredoc(char *str, int *flag)
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
		if (str[i] == '\"' || str[i] == '\'')
		{
			(*flag) = 1;
			str_divide_join(&new, str, start, i);
			temp = check_and_change_str(str, &i);
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

static char	*check_and_change_str(char *str, int *i)
{
	char	*temp;

	temp = NULL;
	if (str[*i] == '\"')
		temp = remove_dobulequote_heredoc(str, i);
	else if (str[*i] == '\'')
		temp = remove_singlequote_heredoc(str, i);
	return (temp);
}

static char	*remove_dobulequote_heredoc(char *str, int *i)
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
			return (removed_str);
		}
		(*i)++;
	}
	return (NULL);
}

static char	*remove_singlequote_heredoc(char *str, int *i)
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

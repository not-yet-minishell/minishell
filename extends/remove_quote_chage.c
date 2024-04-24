/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_chage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:46:18 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/24 10:07:33 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_spacial_char(char *str, int i);
static void	change_wildcard(char **str, int *i);
static char	*check_and_change_str(char *str, int *i, t_list *env);

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
			change_wildcard(&str, &i);
		else if (check_spacial_char(str, i))
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

int	check_spacial_char(char *str, int i)
{
	if (str[i] == '\"' || str[i] == '\'' || \
		(str[i] == '$' && (str[i + 1] != '\0' && str[i + 1] != ' ')))
		return (1);
	return (0);
}

void	change_wildcard(char **str, int *i)
{
	(*str)[*i] = '\12';
	(*i)++;
}

char	*check_and_change_str(char *str, int *i, t_list *env)
{
	char	*temp;

	temp = NULL;
	if (str[*i] == '\"')
		temp = remove_dobulequote(str, i, env);
	else if (str[*i] == '\'')
		temp = remove_singlequote(str, i);
	else if (str[*i] == '$' && (str[*i + 1] != '\0' && str[*i + 1] != ' '))
		temp = extends_find_env(str, i, env);
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/12 17:35:07 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#define EX 30;

char	*remove_singlequote(char *str, int *i);
char	*remove_dobulequote(char *str, int *i, t_list *env);
void	change_str(char *str, t_list *env, t_list *curr);
void	str_divide_join(char **new, char *str,int start,int i);
char	*find_env_value(t_list *head, char *key);
char 	*fine_env(char *str, int *i, t_list *env);
void	extends_env(t_list *env, t_list *head)
{
	t_list	*curr;
	t_token	*token;
	char	*str;
	char	*temp;
	(void)env;

	if (head == NULL)
		return ;
	curr = head->next;
	temp = NULL;
	while(curr)
	{
		token = (t_token *)curr->content;
		if (!token)
			continue;
		if (token->type == WORD)
		{
			str = token->str;
			change_str(str, env, curr);
		}
		curr = curr->next;
	}
}

void	change_str(char *str, t_list *env, t_list *curr)
{
	int		i = 0;
	int		start = 0;
	char	*new;
	char	*temp;

	new = ft_strdup("\0");
	while(str[i])
	{
		if (str[i] == '\"')
		{
			str_divide_join(&new,str,start,i);
			temp = remove_dobulequote(str, &i, env);
			new = ft_strjoin(new, temp, 0);
			if (temp)
				free(temp);
			start = i;
		}else if (str[i] == '\'')
		{
			str_divide_join(&new,str,start,i);
			temp = remove_singlequote(str, &i);
			new = ft_strjoin(new, temp, 0);
			if (temp)
				free(temp);
			start = i;
		}else if (str[i] == '$')
		{
			str_divide_join(&new,str,start,i);
			temp = fine_env(str,&i,env);
			if (temp != NULL){
				new = ft_strjoin(new, temp, 0);
			}
			if (temp)
				free(temp);
			start = i;
		}
		else
			i++;
	}
	temp = ft_substr(str, start, i - start);
	new = ft_strjoin(new, temp, 0);
	free(temp);
	free(((t_token *)curr->content)->str);
	((t_token *)curr->content)->str = new;
}

void	str_divide_join(char **new, char *str,int start,int i)
{
	char *temp;

	temp = ft_substr(str, start, i - start );
	(*new) = ft_strjoin(*new, temp, 0);
	if (temp)
		free(temp);
}

char 	*fine_env(char *str, int *i, t_list *env)
{
	int		env_start;
	char	*key;
	char	*value;

	value = NULL;
	(*i)++;
	if (str[*i] == '\?')
	{
		value = ft_strdup("exitcode");
		(*i)++;
	}
	else
	{
		env_start = *i;
		while (ft_isalnum((int)str[*i]))
			(*i)++;
		key = ft_substr(str, env_start, (*i) - env_start);
		value = find_env_value(env, key);
		// return value를 하게 되면 붙일 수 있다...! 즉,
		//*new = ft_strjoin(*new, value, 0);
	}
	return (value);
}

char	*chage_env_key_to_value(char *str, t_list *env)
{
	int		i = 0;
	int		start;
	char	*new;
	char	*temp;

	(void)env;
	new = ft_strdup("\0");
	start = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			str_divide_join(&new,str,start,i);
			temp = fine_env(str,&i,env);
			if (temp != NULL)
				new = ft_strjoin(new,temp,0);
			if (temp)
				free(temp);
			start = i;
		}
		else
			i++;
	}
	temp = ft_substr(str, start, i - start);
	new = ft_strjoin(new, temp, 0);
	if (temp)
		free(temp);
	return new;
}

char	*find_env_value(t_list *head, char *key)
{
	t_list	*curr;
	t_env	*content;

	if (head == NULL || head->next == NULL)
		return NULL;
	curr = head->next;
	while (curr != NULL)
	{
		content = curr->content;
		if (ft_strncmp(key, content->key, ft_strlen(key)) == 0)
		{
			return ft_strdup(content->value);
		}
		curr = curr->next;
	}
	return NULL;
}

char	*remove_dobulequote(char *str, int *i, t_list *env)
{
	char *removed_str;
	int	start;
	(void)env;

	(*i)++;
	start = (*i);
	while(str[*i])
	{
		if (str[*i] == '\"')
		{
			removed_str = ft_substr(str,start,(*i) - start);
			(*i)++;
			return chage_env_key_to_value(removed_str, env);
		}
		(*i)++;
	}
	return NULL;
}


char	*remove_singlequote(char *str, int *i)
{
	char *removed_str;
	int	start;

	(*i)++;
	start = (*i);
	while(str[*i])
	{
		if (str[*i] == '\'')
		{
			removed_str = ft_substr(str,start,(*i) - start);
			(*i)++;
			return removed_str;
		}
		(*i)++;
	}
	return NULL;
}

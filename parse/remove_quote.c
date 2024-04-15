/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/15 17:40:58 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	extends_env_cmd(t_list *env, t_list *cmd_list);
void	extends_env_rd(t_list *env, t_list *rd_list);
char	*remove_singlequote(char *str, int *i);
char	*remove_dobulequote(char *str, int *i, t_list *env);
char	*change_str(char *str, t_list *env);
void	str_divide_join(char **new, char *str,int start,int i);
char	*find_env_value(t_list *head, char *key);
char 	*fine_env(char *str, int *i, t_list *env);

void	extends_env(t_list *env, t_list **cmd_list){
	t_list	*curr;

	curr = *cmd_list;
	while (curr)
	{
		extends_env_rd(env, ((t_cmd_node *)(*cmd_list)->content)->rd_list);
		extends_env_cmd(env, (*cmd_list)->content);
		curr = curr->next;
	}
	
}

void	extends_env_rd(t_list *env, t_list *rd_list)
{
	t_list	*curr_rd;
	char	*str;
	char	*new_str;

	curr_rd = rd_list->next;
	while (curr_rd)
	{
		str = ((t_rd_node *)curr_rd->content)->filename;
		if (str == NULL)
			break;
		new_str = change_str(str,env);
		((t_rd_node *)curr_rd->content)->filename = new_str;
		free(str);
		curr_rd = curr_rd->next;
	}
}

void	extends_env_cmd(t_list *env, t_list *cmd_list)
{
	t_list	*curr_cmd;
	char	*str;
	char	*new_str;
	(void)env;

	curr_cmd = cmd_list->next;
	while (curr_cmd)
	{
		str = curr_cmd->content;
		if (str == NULL)
			break;
		new_str = change_str(str, env);
		curr_cmd->content = new_str;
		free(str);
		curr_cmd = curr_cmd->next;
	}
}

// void	extends_env(t_list *env, t_list *head)
// {
// 	t_list	*curr;
// 	t_token	*token;
// 	char	*str;

// 	if (head == NULL)
// 		return ;
// 	curr = head->next;
// 	while(curr)
// 	{
// 		token = (t_token *)curr->content;
// 		if (!token)
// 			continue;
// 		if (token->type == WORD)
// 		{
// 			str = token->str;
// 			change_str(str, env, curr);
// 		}
// 		curr = curr->next;
// 	}
// }

char	*change_str(char *str, t_list *env)
{
	int		i = 0;
	int		start = 0;
	char	*new;
	char	*temp;
	char	*prev;

	prev = ft_strdup("\0");
	new = prev;
	while(str[i])
	{
		if (str[i] == '\"' || str[i] == '\'' || str[i] == '$')
		{
			str_divide_join(&new,str,start,i);
			if (str[i] == '\"')
				temp = remove_dobulequote(str, &i, env);
			else if (str[i] == '\'')
				temp = remove_singlequote(str, &i);
			else if (str[i] == '$')
				temp = fine_env(str,&i,env);
			if (temp != NULL){
				prev = new;
				new = ft_strjoin(prev, temp, 0);
				free(prev);
				// ft_strjoin이 이전의 것을 없앰...
				free(temp);
			}
			start = i;
		}
		else
			i++;
	}
	temp = ft_substr(str, start, i - start);
	prev = new;
	new = ft_strjoin(prev, temp, 0);
	free(prev);
	free(temp);
	return new;
}

void	str_divide_join(char **new, char *str,int start,int i)
{
	char	*temp;
	char	*prev;

	temp = ft_substr(str, start, i - start );
	prev = *new;
	(*new) = ft_strjoin(prev, temp, 0);
	free(prev);
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
		free(key);
	}
	return (value);
}

char	*chage_env_key_to_value(char *str, t_list *env)
{
	int		i;
	int		start;
	char	*new;
	char	*temp;
	char	*prev;

	i = 0;
	new = ft_strdup("\0");
	start = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			str_divide_join(&new,str,start,i);
			temp = fine_env(str,&i,env);
			if (temp != NULL){
				prev = new;
				new = ft_strjoin(new,temp,0);
				free(prev);
			}
			if (temp)
				free(temp);
			start = i;
		}
		else
			i++;
	}
	temp = ft_substr(str, start, i - start);
	prev = new;
	new = ft_strjoin(new, temp, 0);
	if (temp)
		free(temp);
	free(str);
	free(prev);
	return (new);
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
			return (ft_strdup(content->value));
		}
		curr = curr->next;
	}
	return (NULL);
}

char	*remove_dobulequote(char *str, int *i, t_list *env)
{
	char	*removed_str;
	int	start;

	(*i)++;
	start = (*i);
	while(str[*i])
	{
		if (str[*i] == '\"')
		{
			removed_str = ft_substr(str,start,(*i) - start);
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
	while(str[*i])
	{
		if (str[*i] == '\'')
		{
			removed_str = ft_substr(str,start,(*i) - start);
			(*i)++;
			return (removed_str);
		}
		(*i)++;
	}
	return (NULL);
}

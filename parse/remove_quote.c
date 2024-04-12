/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/12 13:41:57 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			//free(token->str);
			//token->str = temp;
			// 따옴표 있는지 돌면서 확인!
			// str을 돌면서 보되, 밖에 있는 쿼트만 처리해주면 됨.
			// 즉  "를 만났다면 다음 "를 만날때까지는 ' 이친구는 신경쓰지 않아도 됨
			// $를 만났을때 치환해서 주면 됨.
			// 단 모든 경우 문자열로 치환해서 넘겨주고, 띄어쓰기 있을경우만 분리해서 중간에 삽입하면 되는데! 문자열로 주기!
			// 더블쿼트 안에 있는경우, 치환 O 한번만!!!
			// 싱글쿼트 밖에 있는 경우, 치환 X
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
	//int		flag;

	new = ft_strdup("\0");
	while(str[i])
	{
		if (str[i] == '\"')
		{
			str_divide_join(&new,str,start,i);
			// temp = ft_substr(str, start, i - start ); // "이전거까지 붙이기!... 근데... 바로 "이 붙는경우..
			// new = ft_strjoin(new, temp, 0);
			// if (temp)
			// 	free(temp);
			temp = remove_dobulequote(str, &i, env);
			new = ft_strjoin(new, temp, 0);
			start = i;
		}else if (str[i] == '\'')
		{
			str_divide_join(&new,str,start,i);
			// temp = ft_substr(str, start, i - start ); // "이전거까지 붙이기!... 근데... 바로 "이 붙는경우..
			// new = ft_strjoin(new, temp, 0);
			// if (temp)
			// 	free(temp);
			temp = remove_singlequote(str, &i);
			new = ft_strjoin(new, temp, 0);
			start = i;
		}else if (str[i] == '$')
		{
			str_divide_join(&new,str,start,i);
			temp = fine_env(str,&i,env);
			if (temp != NULL){
				// 지금 생 처음에 못들어 오고 있음! 이전게 들어감 why?!
				int idx = 0;
				int env_start = 0;
				t_list	*next;
				t_list	*newlist;
				t_token	*token;
				char	*newchar;

				newlist = NULL;
				if (i == 0 && (temp[idx] == ' ' || temp[idx] == '\t' || temp[idx] == '\n'))
				{
					while (temp[idx] == ' ' || temp[idx] == '\t' || temp[idx] == '\n')
						idx++;
					new = ft_substr(temp,env_start,idx - env_start);
					env_start = idx;
				}
				if ((temp[idx] == ' ' || temp[idx] == '\t' || temp[idx] == '\n'))
				{
					((t_token *)curr->content)->str = new;
				}
				while (temp[idx])
				{
					// if 처음에 띄어쓰기가 있다면 기존건 교체 해버리고... 즉 지금까지 변환해왔던걸로 교체 해야함...
					if (temp[idx] == ' ' || temp[idx] == '\t' || temp[idx] == '\n')
					{
					while (temp[idx] == ' ' || temp[idx] == '\t' || temp[idx] == '\n')
						idx++;
					env_start = idx;
					while (temp[idx] && temp[idx] != ' ' && temp[idx] != '\t' && temp[idx] != '\n')
						idx++;
					newchar = ft_substr(temp, env_start, idx - env_start);
					token = ft_tokennew(newchar, WORD);
					newlist = ft_lstnew(token);
					next = curr->next;
					curr->next = newlist;
					newlist->next = next;
					curr = curr->next;
					env_start = idx;
					}
					else
						idx++;
				}
				if (newlist)
				{
					curr = newlist;
					new = ft_strdup(((t_token *)curr->content)->str);
				}
				else
				{
					new = ft_strjoin(new,temp,0);
				}
				}
			// 되기는 됐는데... 스플릿 말고 다른 방법으로 해야할 듯함! 직접 체킹해가며 해야할듯.
			start = i;
		}
		else
			i++;
		// if (*str == '\'')
		// 	remove_dobulequote(str);
		// else
		// 	ft_strlcat
	}
	temp = ft_substr(str, start, i - start);
	new = ft_strjoin(new, temp, 0);
	free(temp);
	((t_token *)curr->content)->str = new;
	//return new;
}

void	str_divide_join(char **new, char *str,int start,int i)
{
	char *temp;

	temp = ft_substr(str, start, i - start ); // "이전거까지 붙이기!... 근데... 바로 "이 붙는경우..
	(*new) = ft_strjoin(*new, temp, 0);
	if (temp)
		free(temp);
}

char *fine_env( char *str, int *i, t_list *env)
{
	int		env_start;
	char	*key;
	char	*value;

	value = NULL;
	(*i)++;
	if (str[*i] == '\?')
	{
		value = ft_strdup("exitcode");
		//*new = ft_strjoin(*new,temp,0);
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

// char	*chage_env_not_quote(char *str, t_list *env, t_list *token)
// {
// 	int		
// }

char	*chage_env_key_to_value(char *str, t_list *env)
{
	// ㅇㅒ느ㄴ 전부다 돌면서 보는건데... 위위에서는 하나만 봐야함.!
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
			start = i;
		}
		else
			i++;
	}
	temp = ft_substr(str, start, i - start);
	new = ft_strjoin(new, temp, 0);
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
			// 환경변수 치환해줌. 한번만!!!!
			// 환경변수 안에 띄어쓰기 있어도 그냥 그 문자열 그대로 치환함
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
			// 환경변수 치환해줌. 한번만!!!!
			// 환경변수 안에 띄어쓰기 있어도 그냥 그 문자열 그대로 치환함
			return removed_str;
		}
		(*i)++;
	}
	return NULL;
}

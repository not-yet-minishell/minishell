/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/11 20:33:32 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*remove_singlequote(char *str, int *i);
char	*remove_dobulequote(char *str, int *i, t_list *env);
char	*change_str(char *str, t_list *env);
void	str_divide_join(char **new, char *str,int start,int i);
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
			temp = change_str(str, env);
			//free(token->str);
			token->str = temp;
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

char	*change_str(char *str, t_list *env)
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
	return new;
}

void	str_divide_join(char **new, char *str,int start,int i)
{
	char *temp;

	temp = ft_substr(str, start, i - start ); // "이전거까지 붙이기!... 근데... 바로 "이 붙는경우..
	(*new) = ft_strjoin(*new, temp, 0);
	if (temp)
		free(temp);
}

char	*chage_env_in_doublequote(char *str, t_list *env)
{
	int		i = 0;
	int		start;
	char	*new;
	char	*temp;\

	(void)env;
	new = ft_strdup("\0");
	start = 0;
	while (str[i])
	{
		if (str[i] == '\36')
		{
				ft_printf(1,"??\n");
			str_divide_join(&new, str, start, i);
			if (str[i] == '\?')
			{
				temp = ft_strdup("exitcode");
				new = ft_strjoin(new,temp,0);
				i++;
			}
			while (ft_isalnum((int)str[i]))
				i++;
		}
		else
			i++;
	}
	temp = ft_substr(str, start, i - start);
	new = ft_strjoin(new, temp, 0);
	free(temp);
	return new;
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
			return chage_env_in_doublequote(removed_str, env);
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


// char	*chage_env(char *str)
// {
// 	int	i = 0;
// 	while(str[i])
// 	{
// 		if (str[i] == '\$' && str[i+1] != '\?')
// 		{

// 		}
// 	}
// }
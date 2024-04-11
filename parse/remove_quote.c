/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/11 16:10:13 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


char	*remove_dobulequote(char *str);
static char	*change_str(char *str);
void	extends_env(t_list *env, t_list *head)
{
	t_list	*curr;
	t_token	*token;
	char	*str;
	(void)env;

	curr = head->next;
	while(curr)
	{
		token = (t_token *)curr->content;
		if (token->type == WORD)
		{
			str = token->str;
			token->str = change_str(str);
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

char	*change_str(char *str)
{
	int		i = 0;
	int		start = 0;
	char	*new;
	char	*temp;

	new = "\0";
	while(str[i])
	{
		if (str[i] == '\"')
		{
			temp = ft_substr(str, start, i - start);
			new = ft_strjoin(new, temp, 0);
			free(temp);
			temp = remove_dobulequote(str);
			new = ft_strjoin(new, temp, 0);
		}
		// if (*str == '\'')
		// 	remove_dobulequote(str);
		// else
		// 	ft_strlcat
	}
	return new;
}

char	*remove_dobulequote(char *str)
{
	char *removed_str;
	int	i = 0;
	i++;
	while(str[i])
	{
		if (str[i] == '\"')
		{
			removed_str = ft_substr(str,1,i - 1);
			// 환경변수 치환해줌. 한번만!!!!
			// 환경변수 안에 띄어쓰기 있어도 그냥 그 문자열 그대로 치환함
			return removed_str;
		}
		i++;
	}
	return NULL;
}

// char	*remove_singlequote(char *str)
// {
// 	char *removed_str;
// 	int i = 0;
// 	i++;
// 	while(str[i])
// 	{
// 		if (str[i] == '\'')
// 		{
// 			removed_str = ft_substr(str, i, i - 1);
// 			return removed_str;
// 		}
// 		i++;
// 	}
// }

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
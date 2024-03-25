#include "structure.h"

int ft_is_ifs(char c);
int	ft_is_metacharacter(char c);
t_list *tokenizer(char *line, t_list *head)
{
	int		i;
	int		start;
	char	*str;

	i = 0;
	while (line[i])
	{
		while (line[i] && ft_is_ifs(line[i]) && !ft_is_metacharacter(line[i]))
			i++;
		start = i;
		while (line[i] && !ft_is_ifs(line[i]) && !ft_is_metacharacter(line[i]))
			i++;
		if (i - start > 0)
		{
			str = ft_substr(line, start, i - start);
			ft_add_token_node(head,str,WORD);
		}
		else if (ft_is_metacharacter(line[i]))
			ft_tokenizer_metachar(line, &i, start, head);
		// 이전것까지 토큰리스트에 추가
		// is_metacharacter인지 확인하고 metacharacter인 경우 token_list에 추가
	}
	return (head);
}

int ft_is_ifs(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ft_is_metacharacter(char c)
{
	if (c == '|' || c == '&' || c == '(' || c ==')'
	|| c == '>' || c == '<')
		return (1);
	return (0);
}
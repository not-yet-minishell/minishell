#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include "structure.h"

int is_ifs(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	is_metacharacter(char c)
{
	if (c == '|' || c == '(' || c ==')'
	|| c == '>' || c == '<' || c == '>>'
	|| c ==  '<<')
		return (1);
	return (0);
}

t_list *tokenizer(char *str)
{
	t_list	*token_list;
	int				i;
	int				start;
	char 			*str;

	i = 0;
	while (str[i])
	{
		while (str[i] && is_ifs(str[i]))
			i++;
		start = i;
		while (str[i] && !is_ifs(str[i]) && !is_metacharacter(str[i]))
			i++;
		// 이전것까지 토큰리스트에 추가
		// is_metacharacter인지 확인하고 metacharacter인 경우 token_list에 추가
	}
}

int main(void)
{
	char *str;

	while(1)
	{
		// '|', '(', ')', ' ' , '\t', '\n' 기준으로 자르기
		// | 는 다음거 있는지 볼것  * 바로 |가 있어야 ||임,
		//token - redirection,
		str = readline("examshell : ");
		add_history(str); 
		printf("%s\n",str);
	}
}
#include "structure.h"

static int	ft_token_num(char *line, int i);
void		ft_tokenizer_metachar(char *line, int *i, int start, t_list *head)
{
	char	*str;
	int		tokennum;

	tokennum = ft_token_num(line, *i);
	if (tokennum == ERROR)
	{
		printf("parse error\n"); // error 문구 생각하기
		exit(-1); // exit 코드 생각
		//free 해줘야하는지 고려하기..
	}
	else if (tokennum ==  REDIRECT_IN || tokennum == REDIRECT_OUT || tokennum == L_PAREN 
	|| tokennum == R_PAREN || tokennum == PIPE)
	 	*i += 1;
	else if (tokennum == REDIRECT_APPEND || tokennum == REDIRECT_HEREDOC
	|| tokennum == AND_OPERATOR || tokennum == OR_OPERATOR)
		*i += 2;
	str = ft_substr(line, start, *i - start);
	ft_add_token_node(head,str,tokennum);
}

static int	ft_token_num(char *line, int i)
{
	if (line[i] == '<' && line[i + 1] == '<')
		return (REDIRECT_HEREDOC);
	else if (line[i] == '<')
		return (REDIRECT_IN);
	else if (line[i] == '>' && line[i + 1] == '>')
		return (REDIRECT_APPEND);
	else if (line[i] == '>')
		return (REDIRECT_OUT);
	else if (line[i] == '|' && line[i + 1] == '|')
		return (OR_OPERATOR);
	else if (line[i] == '|')
		return (PIPE);
	else if (line[i] == '&' && line[i + 1] == '&')
		return (AND_OPERATOR);
	else if (line[i] == '(')
		return (L_PAREN);
	else if (line[i] ==')')
		return (R_PAREN);
	else
		return (0);
		// ㅇㅣ ㅂㅜ부ㄴ 에러처리 어떻게 할지 생각해보기
}

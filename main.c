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
	if (c == '|' || c == '&' || c == '(' || c ==')'
	|| c == '>' || c == '<')
	// >> 인 경우와 << 인경우 체크해줘야함!
		return (1);
	return (0);
}

void print_node(t_token *node)
{
	if (!node)
		return ;
	printf("str : %s\n", node->str);
	printf("token : %d\n", node->token);
}

void del_token_node(t_token *node)
{
	if (!node)
		return ;
	free(node->str);
	free(node);
}

void	ft_tokenadd(t_list *head, char *str, int tokennum)
{
		t_list	*new_node;
		t_token	*content;

		content = ft_tokennew(str, tokennum);
		if (!content)
			ft_lstclear(&head, (void *)del_token_node);
		new_node = ft_lstnew(content);
		ft_lstadd_back(&head, new_node);
}

// void ft_token_metaadd(char *line, int *i, int start, t_list *head, int tokennum)
// {

// }

void ft_token_metachar(char *line, int *i, int start, t_list *head)
{
	char *str;
	int	tokennum;

	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		tokennum = REDIRECT_HEREDOC;
		// *i += 2;
		// str = ft_substr(line, start, *i - start);
		// ft_tokenadd(head,str,REDIRECT_HEREDOC);
	}
	else if (line[*i] == '<')
	{
		tokennum = REDIRECT_IN;
		// *i += 1;
		// str = ft_substr(line, start, *i - start);
		// ft_tokenadd(head, str, REDIRECT_IN);
	}
	else if (line[*i] == '>' && line[*i + 1] == '>')
	{
		tokennum = REDIRECT_APPEND;

	}
	else if (line[*i] == '>')
	{
		tokennum = REDIRECT_OUT;

	}
	else if (line[*i] == '|' && line[*i + 1] == '|')
	{
		tokennum = OR_OPERATOR;
	}else if (line[*i] == '|')
	{
		tokennum = PIPE;
	}
	else if (line[*i] == '&' && line[*i + 1] == '&')
	{
		tokennum = AND_OPERATOR;
	}
	else if (line[*i] == '(')
	{
		tokennum = L_PAREN;
	}
	else if (line[*i] ==')')
	{
		tokennum = R_PAREN;

	}
	if (tokennum ==  REDIRECT_IN || tokennum == REDIRECT_OUT || tokennum == L_PAREN 
	|| tokennum == R_PAREN || tokennum == PIPE)
	 	*i += 1;
	else if (tokennum == REDIRECT_APPEND || tokennum == REDIRECT_HEREDOC
	|| tokennum == AND_OPERATOR || tokennum == OR_OPERATOR)
		*i += 2;
}

t_list *tokenizer(char *line, t_list *head)
{
	int		i;
	int		start;
	char	*str;

	i = 0;
	while (line[i])
	{
		while (line[i] && is_ifs(line[i]) && !is_metacharacter(line[i]))
			i++;
		start = i;
		while (line[i] && !is_ifs(line[i]) && !is_metacharacter(line[i]))
			i++;
		if (i - start > 0)
		{
			str = ft_substr(line, start, i - start);
			ft_tokenadd(head,str,WORD);
		}
		else if (is_metacharacter(line[i]))
		{
			ft_token_metachar(line, &i, start, head);
		}
		// 이전것까지 토큰리스트에 추가
		// is_metacharacter인지 확인하고 metacharacter인 경우 token_list에 추가
	}
	return head;
}

void leaks (void){
	
}

int main(void)
{
	char *line;
	t_list	*head;

	//atexit(leaks);
	while(1)
	{
		head = ft_lstnew(NULL);
		line = readline("examshell : ");
		add_history(line); 
		tokenizer(line, head);
		printf("%p\n",head);
		ft_lstiter(head, (void *)print_node);
		ft_lstclear(&head, (void *)del_token_node);
	}
}
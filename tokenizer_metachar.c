/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_metachar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:22 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/28 17:10:03 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	ft_token_num(char *line, int i);

void	ft_tokenizer_metachar(char *line, int *i, int start, t_list *head)
{
	char	*str;
	int		tokennum;

	tokennum = ft_token_num(line, *i);
	if (tokennum == ERROR)
	{
		parse_error();
		*i += 1;
		return ;
	}
	else if (tokennum == REDIRECT_IN || tokennum == REDIRECT_OUT
		|| tokennum == L_PAREN || tokennum == R_PAREN
		|| tokennum == PIPE)
		*i += 1;
	else if (tokennum == REDIRECT_APPEND || tokennum == REDIRECT_HEREDOC
		|| tokennum == AND_OPERATOR || tokennum == OR_OPERATOR)
		*i += 2;
	str = ft_substr(line, start, *i - start);
	ft_add_token_node(head, str, tokennum);
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
	else if (line[i] == ')')
		return (R_PAREN);
	else
		return (0);
}

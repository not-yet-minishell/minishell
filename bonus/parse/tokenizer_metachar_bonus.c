/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_metachar_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:22 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 12:50:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"

static int	ft_token_num(char *line, int i);

int	tokenizer_error(t_list *head)
{
	parse_error();
	ft_lstclear(&head, (void *)ft_del_token_node);
	return (0);
}

int	ft_tokenizer_metachar(char *line, int *i, int start, t_list *head)
{
	char	*str;
	int		tokentype;

	tokentype = ft_token_num(line, *i);
	if (tokentype == 0)
		return (tokenizer_error(head));
	else if (tokentype == REDIRECT_IN || tokentype == REDIRECT_OUT
		|| tokentype == L_PAREN || tokentype == R_PAREN
		|| tokentype == PIPE)
		*i += 1;
	else if (tokentype == REDIRECT_APPEND || tokentype == REDIRECT_HEREDOC
		|| tokentype == AND_OPERATOR || tokentype == OR_OPERATOR)
		*i += 2;
	str = ft_substr(line, start, *i - start);
	ft_add_token_node(head, str, tokentype);
	return (TRUE);
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

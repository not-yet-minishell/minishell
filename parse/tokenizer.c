/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:51:18 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/29 18:06:39 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		ft_is_ifs(char c);
int		ft_is_metacharacter(char c);
void	ft_quotemarks(char *line, int *i, char quote);

t_list	*tokenizer(char *line)
{
	int		i;
	int		start;
	t_list	*head;

	i = 0;
	head = ft_lstnew(NULL);
	while (line[i])
	{
		while (line[i] && ft_is_ifs(line[i]) && !ft_is_metacharacter(line[i]))
			i++;
		start = i;
		while (line[i] && !ft_is_ifs(line[i]) && !ft_is_metacharacter(line[i]))
		{
			if (line[i] == '\"' || line[i] == '\"')
				ft_quotemarks(line, &i, line[i]);
			i++;
		}
		if (i - start > 0)
			ft_add_token_node(head, ft_substr(line, start, i - start), WORD);
		else if (ft_is_metacharacter(line[i]))
			ft_tokenizer_metachar(line, &i, start, head);
	}
	return (head);
}

int	ft_is_ifs(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ft_is_metacharacter(char c)
{
	if (c == '|' || c == '&' || c == '(' || c == ')'
		|| c == '>' || c == '<')
		return (1);
	return (0);
}

void	ft_quotemarks(char *line, int *i, char quote)
{

	*i += 1;
	while (line[*i] && line[*i] != quote)
		*i += 1;
	if (line[*i] == '\0' || line[*i] != quote)
		parse_error();
}

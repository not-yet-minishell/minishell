/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:45:34 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/01 17:25:55 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define ERROR 0
# include "../libft/libft.h"
# include <stdio.h>

enum {
	REDIRECT_IN = 1,
	REDIRECT_OUT,
	REDIRECT_APPEND,
	REDIRECT_HEREDOC,
	AND_OPERATOR,
	OR_OPERATOR,
	L_PAREN,
	R_PAREN,
	PIPE,
	WORD,
};

typedef struct s_token {
	char	*str;
	int		token;
}	t_token;

typedef struct s_node {
	char			*syntax;
	t_token			*token;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

t_token	*ft_tokennew(void *str, int tokennum);
void	ft_del_token_node(t_token *node);
void	ft_add_token_node(t_list *head, char *str, int tokennum);
t_list	*tokenizer(char *line);
void	ft_tokenizer_metachar(char *line, int *i, int start, t_list *head);
void	parse_error(void);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:45:34 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/26 19:01:53 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define ERROR 0
# include "libft/libft.h"
# include <stdio.h>

enum {
	AND_OPERATOR = 1,
	OR_OPERATOR,
	L_PAREN,
	R_PAREN,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_APPEND,
	REDIRECT_HEREDOC,
	WORD,
};

typedef struct s_token {
	char	*str;
	int		type;
}	t_token;

typedef struct s_tree {
	t_token			*token;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_token	*ft_tokennew(void *str, int tokennum);
void	ft_del_token_node(t_token *node);
void	ft_add_token_node(t_list *head, char *str, int tokennum);
t_list	*tokenizer(char *line, t_list *head);
void	ft_tokenizer_metachar(char *line, int *i, int start, t_list *head);
void	parse_error(void);
t_tree *parse_tree(t_list **list);

#endif
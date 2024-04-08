/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:45:34 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/08 12:56:02 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define ERROR -1
# define TRUE 1
# include "../libft/libft.h"
# include "parse_list.h"
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

enum {
	LIST = 11,
	SUBLIST,
	PIPELINE,
	CMD,
	SMPCMD,
	RD
};

typedef struct s_token {
	char	*str;
	int		type;
}	t_token;

typedef struct s_tree {
	t_token			*token;
	t_rd_node		*redirect;
	int				status;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_token		*ft_tokennew(void *str, int tokennum);
void		ft_del_token_node(t_token *node);
void		ft_add_token_node(t_list *head, char *str, int tokennum);
t_list		*tokenizer(char *line);
int			ft_tokenizer_metachar(char *line, int *i, int start, t_list *head);
void		parse_error(void);
t_tree		*parse_tree(t_list **list);
void		tree_inorder_print(t_tree *tree);
t_tree		*parse_tree(t_list **list);
t_tree		*ft_tree_new(t_token *token, int status);
t_tree		*syntax_list(t_list **list);
t_tree		*syntax_sublist(t_list **list);
t_tree		*syntax_pipeline(t_list **list);
t_tree		*syntax_cmd(t_list **list);
t_tree		*syntax_simple_cmd(t_list **list);
t_tree		*syntax_redirection(t_list **list);
t_rd_node	*new_rd_node(int rd_type, char *filename);
t_cmd_node	*new_cmd_node(t_list *rd_list, t_list *cmd_list);
t_cmd_node	*new_cmd_tree_pipeline(t_tree *tree);
t_list		*make_pipelist(t_tree *tree);
void		inorder_cmd_tree(t_tree *tree);
void		clear_tree(t_tree *tree);
void		list_shift(t_list **list);
int			is_redicrtion(t_token *token);
void		tree_parser_error(t_list **list, t_tree *tree);
#endif
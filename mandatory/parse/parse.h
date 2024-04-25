/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:45:34 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 11:46:17 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define ERROR -1
# define TRUE 1
//# include "../minishell.h"
# include "../../libft/libft.h"

enum {
	REDIRECT_IN = 1,
	REDIRECT_OUT,
	REDIRECT_APPEND,
	REDIRECT_HEREDOC,
	REDIRECT_AM,
	REDIRECT_DIR,
	AND_OPERATOR,
	OR_OPERATOR,
	L_PAREN,
	R_PAREN,
	PIPE,
	WORD,
	HEREDOC_NOT_EXTEND,
};

enum {
	START = 0,
	AND_TRUE,
	AND_FALSE,
	OR_TRUE,
	OR_FALSE,
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

typedef struct s_rd_node {
	int		rd_type;
	char	*filename;
}	t_rd_node;

typedef struct s_tree {
	t_token			*token;
	t_rd_node		*redirect;
	int				status;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_token		*ft_tokennew(char *str, int tokennum);
void		ft_del_token_node(t_token *node);
void		ft_add_token_node(t_list *head, char *str, int tokennum);
t_list		*tokenizer(char *line);
void		*tokenizer_free(t_list **head);
int			ft_tokenizer_metachar(char *line, int *i, int start, t_list *head);
void		parse_error(void);
void		tree_inorder_print(t_tree *tree);
t_tree		*parse_tree(t_list **list);
t_tree		*syntax_cmd(t_list **list);
t_tree		*ft_tree_new(t_token *token, int status);
int			inorder_cmd_tree(t_tree *tree, t_list *envp, int flag);
void		clear_tree(t_tree *tree);
int			is_redicrtion(t_token *token);
void		tree_parser_error(t_list **list, t_tree *tree);
char		*find_exit_code(t_list *env);
t_tree		*parse(char *line, t_list *env_list);
void		extdns_find_exit_code(int *i, char **value, t_list *env);
#endif
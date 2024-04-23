/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:45:34 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 12:20:43 by soljeong         ###   ########.fr       */
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
	REDIRECT_AM,
	REDIRECT_DIR,
	AND_OPERATOR,
	OR_OPERATOR,
	L_PAREN,
	R_PAREN,
	PIPE,
	WORD,
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
int	inorder_cmd_tree(t_tree *tree, t_list *envp, int flag);
void		clear_tree(t_tree *tree);
void		list_shift(t_list **list);
int			is_redicrtion(t_token *token);
void		tree_parser_error(t_list **list, t_tree *tree);
int			divide_flag(int type, int exit_num);
void		free_pipe_list(t_list *pipelist);
void		free_cmd_list(t_list *cmd);
char		*heredoc(char *lim, int *heredoc_count, t_list *envp);
void		extends_env(t_list *env, t_list **cmd_list);
char		*extends_find_env(char *str, int *i, t_list *env);
void		str_divide_join(char **new, char *str, int start, int i);
void		str_temp_join(char **new, char *temp);
char		*chage_env_key_to_value(char *str, t_list *env);
char		*change_str(char *str, t_list *env);
int			is_match(char *str, char *pattern);
void		wildcard_cmd(t_list **cmd_list);
void		wildcard_rd(t_list **rd_list);
int			has_wildcard(char *str);
int			is_wildcard_dirtory(char *str);
char		*delete_dir_flag(char *str);
char		*find_exit_code(t_list *env);
void		str_divide_join(char **new, char *str, int start, int i);
t_tree		*parse(char *line, t_list *env_list);
void		tree_status_list(t_tree *tree, int *flag, int exit_num);
void		tree_status_pipeline(t_tree * tree, int flag, t_list *envp, int *exit_num);
t_list		*make_pipelist(t_tree *tree);
char		*extends_find_env_firstnum(char *str, int *i, int *env_start);
void		extdns_find_exit_code(int *i, char **value, t_list *env);
void		cmd_wildcard_none(t_list **curr_cmd);
#endif
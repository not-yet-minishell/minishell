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

#define ERROR 0

#include "libft/libft.h"

typedef struct s_token {
	char	*str;
	int		token;
} t_token;

typedef struct s_node {
	char			*syntax;
	t_token			*token;
	struct s_node	*left;
	struct s_node	*right;
} t_node;

t_token	*ft_tokennew(void *str, int tokennum);
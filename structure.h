#define AND_OPERATOR 1
#define OR_OPERATOR 2
#define L_PAREN 3
#define R_PAREN 4
#define PIPE 5
#define REDIRECTION 6
#define WORD 7

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_token_list
{
	void			*token;
	t_token_list	*next;
} t_token_list;


typedef struct s_token {
	char	*str;
	int		token;
} t_token;

typedef struct s_node {
	char	*syntax;
	t_token	*token;
	t_node	*left;
	t_node	*right;
} t_node;
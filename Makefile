NAME = minishell
CFLAGS = -Wall -Wextra -Werror

PARSE_DIR = ./parse/
PARSE_SRCS = ft_tokennew.c\
			ft_add_token_node.c\
			ft_del_token_node.c\
			tokenizer_metachar.c\
			tokenizer.c\
			tokenizer_utils.c\
			parse_error.c\
			token_test.c\
			tree_parser.c\
			tree_parser2.c\
			tree_utils.c\
			parse_test.c\
			find_exitcode.c\
			print_cmd_tree.c\
			parse.c
PARSE = $(addprefix $(PARSE_DIR),$(PARSE_SRCS))
PARSE_OBJS = $(PARSE:.c=.o)

AST_DIR = ./ast/
AST_SRCS = cmd_tree.c\
			cmd_tree_utils.c\
			cmd_tree_traverse.c\
			free_pipe_list.c
AST = $(addprefix $(AST_DIR),$(AST_SRCS))
AST_OBJS = $(AST:.c=.o)

EXTENDS_DIR = ./extends/
EXTENDS_SRCS = remove_quote_chage.c\
			remove_quote.c\
			remove_quote_heredoc.c\
			remove_quote_utils.c\
			extends_find_env.c\
			extends_find_env_utils.c\
			parse_env.c\
			parse_env2.c\
			sort_env.c\
			extends_env.c
EXTENDS = $(addprefix $(EXTENDS_DIR),$(EXTENDS_SRCS))
EXTENDS_OBJS = $(EXTENDS:.c=.o)

WILDCARD_DIR = ./wildcard/
WILDCARD_SRCS = wildcard.c\
				wildcard_utils.c\
				wildcard_match.c\
				wildcard_rd.c\
				wildcard_cmd.c
WILDCARD = $(addprefix $(WILDCARD_DIR),$(WILDCARD_SRCS))
WILDCARD_OBJS = $(WILDCARD:.c=.o)

SIGNAL_DIR = ./signal/
SIGNAL_SRCS = signal.c\
				signal_heredoc.c\
				signal_process.c
SIGNAL = $(addprefix $(SIGNAL_DIR),$(SIGNAL_SRCS))
SIGNAL_OBJS = $(SIGNAL:.c=.o)

PIPE_DIR = ./pipe/
PIPE_SRCS = command.c\
			execute_parse.c\
			execute.c\
			redirect.c\
			start_process.c\
			wait_process.c\
			one_process.c\
			pipe_utile.c\
			heredoc_tree.c\
			heredoc.c\
			heredoc_utils.c\
			error_handler.c
PIPE = $(addprefix $(PIPE_DIR),$(PIPE_SRCS))
PIPE_OBJS = $(PIPE:.c=.o)

EXECUTE_BUILTIN_DIR = ./execute_builtin/
EXECUTE_BUILTIN_SRCS = 	execute_builtin.c\
						cd.c\
						echo.c\
						env.c\
						execute_builtin.c\
						exit.c\
						export.c\
						export_utile.c\
						pwd.c\
						unset.c\
						utile.c
EXECUTE_BUILTIN = $(addprefix $(EXECUTE_BUILTIN_DIR),$(EXECUTE_BUILTIN_SRCS))
EXECUTE_BUILTIN_OBJS  = $(EXECUTE_BUILTIN:.c=.o)

LIBFT_DIR = ./libft/
LIB = $(LIBFT_DIR)libft.a

SRCS = main.c		
OBJS = $(SRCS:.c=.o)
MAKE = make

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@ 

$(NAME) : $(OBJS) $(LIB) $(EXECUTE_BUILTIN_OBJS) $(PIPE_OBJS) $(SIGNAL_OBJS) $(WILDCARD_OBJS) $(EXTENDS_OBJS) $(AST_OBJS) $(PARSE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline

$(LIB) :
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS) $(EXECUTE_BUILTIN_OBJS) $(PIPE_OBJS) $(SIGNAL_OBJS) $(WILDCARD_OBJS) $(EXTENDS_OBJS) $(AST_OBJS) $(PARSE_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

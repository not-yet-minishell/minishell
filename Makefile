NAME = minishell
BONUS = minishell_bonus
CFLAGS = -Wall -Wextra -Werror

PARSE_DIR = ./mandatory/parse/
PARSE_SRCS = ft_tokennew.c\
			ft_add_token_node.c\
			ft_del_token_node.c\
			tokenizer_metachar.c\
			tokenizer.c\
			tokenizer_utils.c\
			parse_error.c\
			tree_parser.c\
			tree_parser2.c\
			tree_utils.c\
			find_exitcode.c\
			print_cmd_tree.c\
			parse.c

PARSE = $(addprefix $(PARSE_DIR),$(PARSE_SRCS))
PARSE_OBJS = $(PARSE:.c=.o)

AST_DIR = ./mandatory/ast/
AST_SRCS = cmd_tree.c\
			cmd_tree_utils.c\
			cmd_tree_traverse.c\
			free_pipe_list.c

AST = $(addprefix $(AST_DIR),$(AST_SRCS))
AST_OBJS = $(AST:.c=.o)

EXTENDS_DIR = ./mandatory/extends/
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

WILDCARD_DIR = ./mandatory/wildcard/
WILDCARD_SRCS = wildcard.c\
				wildcard_utils.c\
				wildcard_match.c\
				wildcard_rd.c\
				wildcard_cmd.c

WILDCARD = $(addprefix $(WILDCARD_DIR),$(WILDCARD_SRCS))
WILDCARD_OBJS = $(WILDCARD:.c=.o)

SIGNAL_DIR = ./mandatory/signal/
SIGNAL_SRCS = signal.c\
				signal_heredoc.c\
				signal_process.c

SIGNAL = $(addprefix $(SIGNAL_DIR),$(SIGNAL_SRCS))
SIGNAL_OBJS = $(SIGNAL:.c=.o)

PIPE_DIR = ./mandatory/pipe/
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

EXECUTE_BUILTIN_DIR = ./mandatory/execute_builtin/
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

SRCS = ./mandatory/main.c		
OBJS = $(SRCS:.c=.o)

PARSE_DIR_BONUS = ./bonus/parse/
PARSE_SRCS_BONUS = ft_tokennew_bonus.c\
					ft_add_token_node_bonus.c\
					ft_del_token_node_bonus.c\
					tokenizer_metachar_bonus.c\
					tokenizer_bonus.c\
					tokenizer_utils_bonus.c\
					parse_error_bonus.c\
					tree_parser_bonus.c\
					tree_parser2_bonus.c\
					tree_utils_bonus.c\
					find_exitcode_bonus.c\
					print_cmd_tree_bonus.c\
					parse_bonus.c

PARSE_BONUS = $(addprefix $(PARSE_DIR_BONUS),$(PARSE_SRCS_BONUS))
PARSE_OBJS_BONUS = $(PARSE_BONUS:.c=.o)

AST_DIR_BONUS = ./bonus/ast/
AST_SRCS_BONUS = cmd_tree_bonus.c\
					cmd_tree_utils_bonus.c\
					cmd_tree_traverse_bonus.c\
					free_pipe_list_bonus.c

AST_BONUS = $(addprefix $(AST_DIR_BONUS),$(AST_SRCS_BONUS))
AST_OBJS_BONUS = $(AST_BONUS:.c=.o)

EXTENDS_DIR_BONUS = ./bonus/extends/
EXTENDS_SRCS_BONUS = remove_quote_chage_bonus.c\
						remove_quote_bonus.c\
						remove_quote_heredoc_bonus.c\
						remove_quote_utils_bonus.c\
						extends_find_env_bonus.c\
						extends_find_env_utils_bonus.c\
						parse_env_bonus.c\
						parse_env2_bonus.c\
						sort_env_bonus.c\
						extends_env_bonus.c

EXTENDS_BONUS = $(addprefix $(EXTENDS_DIR_BONUS),$(EXTENDS_SRCS_BONUS))
EXTENDS_OBJS_BONUS = $(EXTENDS_BONUS:.c=.o)

WILDCARD_DIR_BONUS = ./bonus/wildcard/
WILDCARD_SRCS_BONUS = wildcard_bonus.c\
						wildcard_utils_bonus.c\
						wildcard_match_bonus.c\
						wildcard_rd_bonus.c\
						wildcard_cmd_bonus.c

WILDCARD_BONUS = $(addprefix $(WILDCARD_DIR_BONUS),$(WILDCARD_SRCS_BONUS))
WILDCARD_OBJS_BONUS = $(WILDCARD_BONUS:.c=.o)

SIGNAL_DIR_BONUS = ./bonus/signal/
SIGNAL_SRCS_BONUS = signal_bonus.c\
					signal_heredoc_bonus.c\
					signal_process_bonus.c

SIGNAL_BONUS = $(addprefix $(SIGNAL_DIR_BONUS),$(SIGNAL_SRCS_BONUS))
SIGNAL_OBJS_BONUS= $(SIGNAL_BONUS:.c=.o)

PIPE_DIR_BONUS = ./bonus/pipe/
PIPE_SRCS_BONUS = command_bonus.c\
					execute_parse_bonus.c\
					execute_bonus.c\
					redirect_bonus.c\
					start_process_bonus.c\
					wait_process_bonus.c\
					one_process_bonus.c\
					pipe_utile_bonus.c\
					heredoc_tree_bonus.c\
					heredoc_bonus.c\
					heredoc_utils_bonus.c\
					error_handler_bonus.c

PIPE_BONUS = $(addprefix $(PIPE_DIR_BONUS),$(PIPE_SRCS_BONUS))
PIPE_OBJS_BONUS = $(PIPE_BONUS:.c=.o)

EXECUTE_BUILTIN_DIR_BONUS = ./bonus/execute_builtin/
EXECUTE_BUILTIN_SRCS_BONUS = 	execute_builtin_bonus.c\
								cd_bonus.c\
								echo_bonus.c\
								env_bonus.c\
								execute_builtin_bonus.c\
								exit_bonus.c\
								export_bonus.c\
								export_utile_bonus.c\
								pwd_bonus.c\
								unset_bonus.c\
								utile_bonus.c

EXECUTE_BUILTIN_BONUS = $(addprefix $(EXECUTE_BUILTIN_DIR_BONUS),$(EXECUTE_BUILTIN_SRCS_BONUS))
EXECUTE_BUILTIN_OBJS_BONUS = $(EXECUTE_BUILTIN_BONUS:.c=.o)

SRCS_BONUS = ./bonus/main_bonus.c		
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

MAKE = make

all : $(NAME)

bonus : $(BONUS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(EXECUTE_BUILTIN_OBJS) $(PIPE_OBJS) $(SIGNAL_OBJS) $(WILDCARD_OBJS) $(EXTENDS_OBJS) $(AST_OBJS) $(PARSE_OBJS) $(BONUS_OBJS)
	rm -f $(OBJS_BONUS) $(EXECUTE_BUILTIN_OBJS_BONUS) $(PIPE_OBJS_BONUS) $(SIGNAL_OBJS_BONUS) $(WILDCARD_OBJS_BONUS) $(EXTENDS_OBJS_BONUS) $(AST_OBJS_BONUS) $(PARSE_OBJS_BONUS)

fclean:
	make clean
	rm -f $(LIB)
	rm -f $(NAME)
	rm -f $(BONUS)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME) : $(OBJS) $(LIB) $(EXECUTE_BUILTIN_OBJS) $(PIPE_OBJS) $(SIGNAL_OBJS) $(WILDCARD_OBJS) $(EXTENDS_OBJS) $(AST_OBJS) $(PARSE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline

$(BONUS) : $(OBJS_BONUS) $(LIB) $(EXECUTE_BUILTIN_OBJS_BONUS) $(PIPE_OBJS_BONUS) $(SIGNAL_OBJS_BONUS) $(WILDCARD_OBJS_BONUS) $(EXTENDS_OBJS_BONUS) $(AST_OBJS_BONUS) $(PARSE_OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline

$(LIB) :
	$(MAKE) -C $(LIBFT_DIR) bonus

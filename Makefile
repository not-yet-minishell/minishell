NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
SRCS = main.c\
		parse/ft_tokennew.c\
		parse/ft_add_token_node.c\
		parse/ft_del_token_node.c\
		parse/tokenizer_metachar.c\
		parse/tokenizer.c\
		parse/tokenizer_utils.c\
		parse/parse_error.c\
		parse/token_test.c\
		parse/tree_parser.c\
		parse/tree_parser2.c\
		parse/tree_utils.c\
		parse/parse_test.c\
		parse/find_exitcode.c\
		parse/print_cmd_tree.c\
		parse/parse.c\
		ast/cmd_tree.c\
		ast/cmd_tree_utils.c\
		ast/cmd_tree_traverse.c\
		ast/free_pipe_list.c\
		extends/remove_quote_chage.c\
		extends/remove_quote.c\
		extends/remove_quote_heredoc.c\
		extends/remove_quote_utils.c\
		extends/extends_find_env.c\
		extends/extends_find_env_utils.c\
		extends/parse_env.c\
		extends/parse_env2.c\
		wildcard/wildcard.c\
		wildcard/wildcard_utils.c\
		wildcard/wildcard_match.c\
		wildcard/wildcard_rd.c\
		wildcard/wildcard_cmd.c\
		signal/signal.c\
		signal/signal_heredoc.c\
		signal/signal_process.c\
		extends/sort_env.c\
		extends/extends_env.c\
		pipe/command.c\
		pipe/execute_parse.c\
		pipe/execute.c\
		pipe/redirect.c\
		pipe/start_process.c\
		pipe/wait_process.c\
		pipe/one_process.c\
		pipe/pipe_utile.c\
		pipe/heredoc_tree.c\
		pipe/heredoc.c\
		pipe/heredoc_utils.c\
		execute_builtin/cd.c\
		execute_builtin/echo.c\
		execute_builtin/env.c\
		execute_builtin/execute_builtin.c\
		execute_builtin/exit.c\
		execute_builtin/export.c\
		execute_builtin/export_utile.c\
		execute_builtin/pwd.c\
		execute_builtin/unset.c\
		execute_builtin/utile.c\
		get_next_line/get_next_line_bonus.c\
		get_next_line/get_next_line_utils_bonus.c\
		error_handler.c
		
OBJS = $(SRCS:.c=.o)
MAKE = make

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@ 

$(NAME) : $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C printf
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) -Llibft -Lprintf -lft -lftprintf  -lreadline

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C printf clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f printf/libftprintf.a
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus

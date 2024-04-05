NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRCS = main.c\
		parse/ft_tokennew.c\
		parse/ft_add_token_node.c\
		parse/ft_del_token_node.c\
		parse/tokenizer_metachar.c\
		parse/tokenizer.c\
		parse/parse_error.c\
		parse/token_test.c\
		parse/tree_parser.c\
		parse/tree_parser2.c\
		parse/list_utils.c\
		parse/tree_utils.c\
		parse/parse_test.c\
		parse/parse_env.c\
		parse/sort_env.c\
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
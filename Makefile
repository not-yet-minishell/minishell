NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
PARSEDIR = parse
SRCS = main.c\
		$(PARSEDIR)/ft_tokennew.c\
		$(PARSEDIR)/ft_add_token_node.c\
		$(PARSEDIR)/ft_del_token_node.c\
		$(PARSEDIR)/tokenizer_metachar.c\
		$(PARSEDIR)/tokenizer.c\
		$(PARSEDIR)/parse_error.c\
		$(PARSEDIR)/token_test.c\
		error_handler.c
OBJS = $(SRCS:.c=.o)
MAKE = make

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@

$(NAME) : $(OBJS)
	make -C libft
	make -C printf
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) -Llibft -Lprintf -lft -lftprintf  -lreadline

clean:
	rm -rf $(OBJS)
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f libft/libft.a
	rm -f printf/libftprintf.a
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
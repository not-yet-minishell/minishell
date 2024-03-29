NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c\
		ft_tokennew.c\
		ft_add_token_node.c\
		ft_del_token_node.c\
		tokenizer_metachar.c\
		tokenizer.c\
		parse_error.c\
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
	make -C libft clean
	make -C printf clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f printf/libftprintf.a
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c\
		ft_tokennew.c\
		ft_add_token_node.c\
		ft_del_token_node.c\
		tokenizer_metachar.c\
		tokenizer.c
OBJS = $(SRCS:.c=.o)
SUBDIRS = libft
MAKE = make

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@

$(NAME) : $(OBJS)
	make -C $(SUBDIRS)
	cp $(SUBDIRS)/libft.a $(NAME)
	$(CC) $(CFLAGS) -I. $(OBJS)  -o $(NAME)  -lft -L$(SUBDIRS) -lreadline

clean:
	make -C $(SUBDIRS) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(SUBDIRS)/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
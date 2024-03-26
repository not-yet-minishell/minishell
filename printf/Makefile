CC = cc
CFLAGS = -Wall -Wextra -Werror
SCRS = ft_printf.c print_format.c print_format2.c
NAME = libftprintf.a
OBJECTS = $(SCRS:.c=.o)

all : $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re

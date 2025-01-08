NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
AR=ar rcs

SOURCES = ft_printf.c ft_putchar.c ft_putstr.c ft_puthex.c ft_putnbr.c ft_putnbr_u.c

OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
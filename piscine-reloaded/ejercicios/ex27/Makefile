NAME    = ft_display_file
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

SRC     = ft_display_file.c
OBJS    = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

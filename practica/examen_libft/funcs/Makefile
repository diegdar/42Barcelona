# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/08 13:44:58 by dichacon          #+#    #+#              #
#    Updated: 2026/06/11 20:01:49 by dichacon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = my_library.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = my_library.h

SRC = ft_isalpha.c\
			ft_memmove.c\
	

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) Makefile $(INC)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


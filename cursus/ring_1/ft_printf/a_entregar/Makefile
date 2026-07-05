# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/04 17:51:21 by dichacon          #+#    #+#              #
#    Updated: 2026/07/04 18:48:26 by dichacon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = ft_printf.h

SRC = ft_printf.c ft_printf_utils.c

LIBFT_DIR = libft
LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c Makefile $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean: 
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclan

re: fclean all

.PHONY: all clean fclean re

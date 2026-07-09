# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/04 17:51:21 by dichacon          #+#    #+#              #
#    Updated: 2026/07/06 19:23:09 by dichacon         #   .fr        #
#                                                                              #
# **************************************************************************** #
NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INC     = ft_printf.h

SRC     = ft_printf.c \
	ft_printf_utils.c \
	ft_printf_chars.c \
	ft_printf_nums.c \
	ft_printf_hex.c

OBJ     = $(SRC:.c=.o)

# Regla principal obligatoria
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c Makefile $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# --- REGLA DE PRUEBAS AUTOMÁTICAS ---
test: $(NAME)
	$(CC) $(CFLAGS) -I . ../main.c $(NAME) -o ../test_printf
	./../test_printf
	@echo "✨ ¡Test compilado en la carpeta superior!"

# --- REGLA PARA DEBUGAR CON GDB ---
debug: CFLAGS += -g3
debug: re
	$(CC) $(CFLAGS) -I . ../main.c $(NAME) -o ../test_printf
	gdb ../test_printf
	@echo "🐛 Compilado en modo DEBUG con -g3. Listo para GDB."

.PHONY: all clean fclean re test debug


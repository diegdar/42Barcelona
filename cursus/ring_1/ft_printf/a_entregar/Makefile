# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/04 17:51:21 by dichacon          #+#    #+#              #
#    Updated: 2026/07/05 19:52:45 by dichacon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INC     = ft_printf.h

SRC     = ft_printf.c ft_printf_utils.c 
OBJ     = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

# Regla principal obligatoria
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
	make -C $(LIBFT_DIR) fclean

re: fclean all

# --- REGLA DE PRUEBAS AUTOMÁTICA ---
test: $(NAME)
	$(CC) $(CFLAGS) -I . ../main.c $(NAME) -o ../test_printf
	./../test_printf
	@echo "✨ ¡Test compilado en la carpeta superior!"

# --- NUEVA REGLA PARA DEBUGAR CON GDB ---
debug: CFLAGS += -g3
debug: re
	$(CC) $(CFLAGS) -I . ../main.c $(NAME) -o ../test_printf
	gdb ../test_printf
	@echo "🐛 Compilado en modo DEBUG con -g3. Listo para GDB."

.PHONY: all clean fclean re test debug


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/23 15:45:33 by dichacon          #+#    #+#              #
#    Updated: 2026/04/23 17:30:39 by dichacon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# 1. Nombre de la librería
NAME = libft.a

# 2. Directorios
DIR_SRC = srcs/
DIR_INC = includes/

# 3. Archivos fuente (Rutas completas)
SRCS_FILES	= ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRCS		= $(addprefix $(DIR_SRC), $(SRCS_FILES))

# 4. Archivos objeto (Se generan a partir de los .c)
OBJS		= $(SRCS:.c=.o)

# 5. Compilador y Flags
CFLAGS = -Wall -Wextra -Werror
# Flag para incluir la carpeta de cabeceras
IFLAGS		= -I $(DIR_INC)

# --- REGLAS ---

# Regla principal
all:	$(NAME)

# Cómo crear la librería a partir de los objetos	
$(NAME): $(OBJS)
# r: reemplaza archivos antiguos, c: crea la librería si no existe
	ar rc $(NAME) $(OBJS)
# Genera un índice dentro de la librería para que sea más rápida de usar
	ranlib $(NAME)
	
# Regla genérica para compilar archivos .c a .o
# $< es el archivo .c (fuente)
# $@ es el archivo .o (destino)
.c.o:
	cc $(CFLAGS) -c $< -o $@ -I $(DIR_INC)
	
# Borra los archivos objeto (.o)	
clean:
	rm -f $(OBJS)
		
# Borra objetos y la librería	
fclean: clean
	rm -f $(NAME)
	
# Recompila todo desde cero	
re:	fclean all

# Marcamos estas reglas como 'falsas' para que no se confundan con archivos
.PHONY: all clean fclean re	

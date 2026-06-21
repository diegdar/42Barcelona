#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> //para atoi

int	main(int argc, char *argv[])
{
	size_t			n;
	void			*src;
	unsigned char	dest[100];
	size_t			i;

	if (argc < 3)
	{
		printf("Uso: %s [texto_src] [num_bytes]\n", argv[0]);
		return (1);
	}

	src = argv[1];
	n = atoi(argv[2]);//convierte texto a numero de la terminal	
	if (n > 100)
		n = 100;
	
	ft_memcpy(dest, src, n);
	printf("Resultado en DEST (Hexadecimal): \n");
	i = 0;
	while (i < n)
	{
	// %02x imprime el byte en hexadecimal (ej: 0a, ff, 42)
		printf("%02x ", dest[i]);
		i++;
	}
	printf("\n\nResultado en DEST (Como texto):\n");
    write(1, dest, n); // Escribimos n bytes directamente a la terminal
    printf("\n");
	return (0);
}

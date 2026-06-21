#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("Uso: %s [texto_src] [num_bytes_to_copy_in_dst]\n", argv[0]);
		return (1);
	}
	char		*src = argv[1];
	char		dst[20];
	size_t		dst_size;
	size_t		res;

	dst_size = atoi(argv[2]);
	res = ft_strlcpy(dst, src, dst_size);
	if (res > dst_size)
	{      
		printf("Cadena truncada!\n. Necesitaba: %zu bytes, tengo: %zu bytes\n", (res + 1), (dst_size + 1));    	
		printf("contenido de src: %s\n", src);
	        printf("Contenido de dest: %s\n", dst); 
	}
	else 
	{
		printf("Copiado con exito!\n");
		printf("contenido de src: %s\n", src);
	        printf("Contenido de dest: %s\n", dst); 
	}
	
	return (0);
}

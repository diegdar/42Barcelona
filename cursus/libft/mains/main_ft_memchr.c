#include "libft.h"
#include <stdio.h>

void	ft_printoutput(unsigned char *out)
{
	if(out)
		printf("Valor encontrado: %c, en direccion fisica: %p\n", *out, out);
	else
		printf("El valor buscado no se encuentra\n");		
}

int	main(void)
{
	char		haystack[20] = "mu%rcielago";
	size_t 		haystack_len;	
	size_t		i;
	unsigned char	*out;
	size_t	n;

	haystack_len = ft_strlen(haystack);	
		
	printf("**Valor de haystack: %s\n\n", haystack);		
	printf("-- Caso 1: Se encuentra el caracter buscado: 'e' buscando en los primeros 8 caracteres --\n");
	n = 8;
	out = ft_memchr(haystack, 'e', n);
	ft_printoutput(out);

	printf("\n-- Caso 2: No Se encuentra el caracter buscado: 'e' en los primeros 4 caracteres --\n");
	n = 4;
	out = ft_memchr(haystack, 'e', n);
	ft_printoutput(out);

	printf("\n-- Caso 3: Se encuentra el nulo '\\0'(nulo) --\n");
	n = 12;	
	out = ft_memchr(haystack, '\0', n);
	printf("El valor '\\0' se encontro en la direccion fisica: %p\n", out);

	printf("\n-- Caso 4: Se encuentra un caracter especial: %% --\n");
	n = 12;		
	out = ft_memchr(haystack, '%', n);
	printf("El valor '%%' se encontro en la direccion fisica: %p\n", out);

	printf("\n**Direcciones fisicas de haystack:\n");
	i = 0;
	while (i <= haystack_len)
	{
		printf("Index:%zu. caracter: %c Direc_memoria: %p\n", i, haystack[i], (haystack + i));
		i++;
	}
	return (0);
}

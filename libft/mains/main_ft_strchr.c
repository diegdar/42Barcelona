#include "libft.h"
#include <stdio.h>

void	ft_printoutput(char *out)
{
	if(out)
		printf("Valor encontrado: %c, en direccion fisica: %p\n", *out, out);
	else
		printf("El valor buscado no se encuentra\n");		
}

int	main(void)
{
	char	haystack[20] = "hello";
	size_t 	haystack_len;	
	size_t	i;
	char	*out;

	haystack_len = ft_strlen(haystack);	

		
	printf("**Valor de haystack: %s\n\n", haystack);		
	printf("-- Caso 1: Se encuentra el caracter buscado: 'e' --\n");		
	out = ft_strchr(haystack, 'e');
	ft_printoutput(out);

	printf("\n-- Caso 2: No Se encuentra el caracter buscado: 'd' --\n");
	out = ft_strchr(haystack, 'd');	
	ft_printoutput(out);

	printf("\n-- Caso 3: Se encuentra el '\\0'(nulo) --\n");		
	out = ft_strchr(haystack, '\0');
	printf("En valor '\\0' se encontro en la direccion fisica: %p\n", out);

	printf("\n**Direcciones fisicas de haystack:\n");
	i = 0;
	while (i <= haystack_len)
	{
		printf("Index:%zu. Direc_memoria: %p\n", i, (haystack + i));
		i++;
	}
	return (0);
}

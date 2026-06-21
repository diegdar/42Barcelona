#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	test_fn(char *s, char (*f) (unsigned int, char), char *test_name)
{
	char	*res;

	printf("\n--- Test: %s ---", test_name);

	printf("\n\t*Valor de 's': %s", s);
	res = ft_strmapi(s, f);
	if (!res)
	{
		printf("\nft_strmapi() ha devuelto: NULL\n");
		return ;
	}
	printf("\n\t**Valor devuelto por ft_strmapi(): %s", res);
	printf("\n\t*Longitud de 's': %zu", ft_strlen(s));
	printf("\n\t*Longitud de 'res: %zu\n", ft_strlen(res));

	free(res);
	res = NULL;
}

char	mapi_tolower_test(unsigned int i, char c)
{
	(void)i;
	return ((char)ft_tolower(c));
}

int	main(void)
{
	char	*s;
	s = "HOLA mUnDO!";

	test_fn(s, mapi_tolower_test, "Paso de la funcion ft_tolower() pasando una cadena.");

	s = "";
	test_fn(s, mapi_tolower_test, "Paso de la funcion ft_tolower() pasando una cadena vacia.");

	s = NULL;
	test_fn(s, mapi_tolower_test, "Paso de la funcion ft_tolower() pasando una variable NULL.");
	return (0);
}


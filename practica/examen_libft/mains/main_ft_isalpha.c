#include "my_library.h"
#include <stdio.h>

void	test_fn(char	*test_name, char	c)
{
	printf("\n--- TEST: %s ---", test_name);
	printf("\n*Valor recibido por parametro: '%c'", c);
	printf("\n*Valor valor devuelto por la funcion(): %d\n", ft_isalpha(c));
}

int	main(void)
{
	char	c;

	c = 'a';
	test_fn("Paso de un caracater en minusculas", c);

	return (0);
}

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	test_fn(int num, char *test_name)
{
	char	*res;

	printf("\n--- Test: %s ---", test_name);

	printf("\n\t*Valor parametro num(int): %d", num);
	res = ft_itoa(num);
	printf("\n\t*Valor devuelto por ft_itoa(): %s\n", res);
	free(res);
	res = 0;
}

int	main(void)
{
	int	num;

	num = 4;
	test_fn(num, "Paso de un entero positivo de 1 digito");

	num = 42;
	test_fn(num, "Paso de un entero positivo de 2 digitos");

	num = 425;
	test_fn(num, "Paso de un entero positivo de 3 digitos");

	num = -4;
	test_fn(num, "Paso de un entero NEGATIVO de 1 digito");

	num = -42;
	test_fn(num, "Paso de un entero NEGATIVO de 2 digitos");

	num = 0;
	test_fn(num, "Paso deL valor 0");

	num = -0;
	test_fn(num, "Paso deL valor 0 en NEGATIVO");

	num = (int)(~0U >> 1);
	test_fn(num, "El valor de num sobrepasa el valor maximo de int");

	num = (1 << 31);
	test_fn(num, "El valor de num supera el valor minimo de int");
	return (0);
}

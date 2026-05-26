#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void print_result(char **r)
{
	size_t	i;

	if (!r)
	{
		printf("\n⚠️ La Funcion ha devuelto un valor NULL\n");
		return ;
	}

	printf("\n***ARREGLO DE LOS PUNTEROS,  direccion: %p\n", r);
	i = 0;
	while(r[i])
	{
		printf("\n\t-Puntero: %zu, valor: '%s', direccion: %p\n", i, r[i], (void *)r[i] );
		i++;
	}
}

static void free_all(char **r)
{
	size_t	i;

	if (!r)
	{
		printf("\n⚠️ La Funcion ha devuelto un valor NULL\n");
		return ;
	}

	i = 0;
	while (r[i])
	{
		free(r[i]);
		i++;
	}
	free(r);
}

static void	test_fn(char *s, char splitter, char *test_name)
{
	char	**result;

	printf("\n--- Test: %s ---", test_name);
	result = ft_split(s, splitter);

	printf("\n**Valor de s: '%s'", s);
	printf("\n**Valor de splitter: '%c'", splitter);
	printf("\n**Valor devuelto por result:");
	print_result(result);
	free_all(result);
}

int	main(void)
{

	char	*s;
	char	splitter;


	s = "hola mundo 42";
	splitter = ' ';
	test_fn(s, splitter, "El Splitter se encuentra en el medio del string.");

	s = " hola mundo 42 ";
	splitter = ' ';
	test_fn(s, splitter, "El Splitter se encuentra en el medio, al principio y final del string.");

	s = "hola  mundo    42 ";
	splitter = ' ';
	test_fn(s, splitter, "Hay varios splitters entre las palabras.");

	s = "hola_mundo_42 ";
	splitter = ' ';
	test_fn(s, splitter, "El splitter no se encuentra en la cadena.");

	s = "";
	splitter = '_';
	test_fn(s, splitter, "La cadena esta vacia.");

	s = "hola mundo 42";
	splitter = '\0';
	test_fn(s, splitter, "Paso de un splitter nulo('\0')");

	s = NULL;
	splitter = '\0';
	test_fn(s, splitter, "Los parametros nulos (NULL, \0)");

	s = "";
	splitter = '\0';
	test_fn(s, splitter, "Splitter nulo('\0') y cadena vacia");

	return (0);
}

#include "libft.h"
#include <stdio.h>

static void	test_fn(char *s, char *set, char *test_name)
{
	char	*result;

	printf("\n--- Test: %s ---", test_name);
	result = ft_strtrim(s, set);

	if (!result)
	{
		printf("\n⚠️ La Funcion ha devuelto un valor NULL\n");
		return ;
	}
	printf("\n**Valor de s: '%s'", s);
	printf("\n\t*Longitud de s: '%zu'", ft_strlen(s));
	printf("\n**Valor de set: '%s'", set);
	printf("\n**Valor de result: '%s'", result);
	printf("\n\t*longitud de result: '%zu'\n", ft_strlen(result));
}

int	main(void)
{
	char	*s;
	char	*set;

	s = " hola";
	set = " ";
	test_fn(s, set, "Eliminacion de 'set' al inicio");

	s = " hola ";
	set = " ";
	test_fn(s, set, "Eliminacion de 'set' al inicio y al final");

	s = "hola ";
	set = " ";
	test_fn(s, set, "Eliminacion de set solo al final");

	s = "\t\nhola";
	set = "\t\n";
	test_fn(s, set, "varios caracteres de eliminacion al principio '\\t\\nhola'");

	s = "   ";
	set = " ";
	test_fn(s, set, "String compuesto solo por espacios y el set es el ' '");

	s = "";
	set = "\n\t";
	test_fn(s, set, "Paso de un string vacio");

	s = NULL;
	set = NULL;
	test_fn(s, set, "Los parametros con punteros nulos (NULL)");

	s = "\n\t";
	set = "\n\t";
	test_fn(s, set, "El recorte vacia por completo el string");
	return (0);
}


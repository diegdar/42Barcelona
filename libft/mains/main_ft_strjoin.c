#include "libft.h"
#include <stdio.h>

static void	test_fn(char *s1, char *s2, char *test_name)
{
	char	*merger;

	printf("\n--- Test: %s ---", test_name);
	printf("\nValor de s1: '%s'", s1);
	printf("\nValor de s2: '%s'", s2);
	merger = ft_strjoin(s1, s2);
	printf("\nValor de merger: '%s'\n", merger);
}

int	main(void)
{
	char	*s1;
	char	*s2;

s1 = "hola";
s2 = " mundo";
test_fn(s1, s2, "Union normal de s1 y s2");

s1 = "";
s2 = " mundo";
test_fn(s1, s2, "s1 con valor vacio");

s1 = "hola";
s2 = "";
test_fn(s1, s2, "s2 con valor vacio");
	return (0);
}

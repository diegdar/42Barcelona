#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	fn_test(char *test_name, char *s, void (*f)(unsigned int, char *))
{
	printf("\n--- Test: %s ---", test_name);

	printf("\n\t*Valor de 's' ANTES de llamar a ft_fn(): %s", s);
ft_striteri(s, f);
	printf("\n\t*Valor de 's' DESPUES: %s\n", s);
}

void	alternate_case(unsigned int i, char *c)
{
	if (!c)
		return ;
	if (i % 2 == 0)
		*c = ft_toupper(*c);
	else
		*c = ft_tolower(*c);
}

int	main(void)
{
	char	s[] = "el mundo de la memoria c!";

	fn_test("paso de un string a la funcion toupper_mem()'",  s, alternate_case);
	return (0);
}

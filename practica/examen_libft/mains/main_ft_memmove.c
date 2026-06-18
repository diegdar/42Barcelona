#include "my_library.h"
#include <stdio.h>

void	fn_test(char	*test_name, char *type, void *dest,const void *src, size_t len)
{
	void	*res;

	printf("\n--- TEST: %s ---", test_name);
	if(*type == 's')
	{
		printf("\n*Valor de src: '%s'", (const char *)src);
		printf("\n*Valor de dest: '%s'", (const char *)dest);
		printf("\n*Valor de len: '%zu'", len);
	res = ft_memmove(dest, src, len);
		printf("\n**Valor devuelto por la funcion(): '%s'\n", (char *)res);
	}
}

int	main(void)
{
	char	s_str[20] = "hola";
	char	*d_str;
//	int	*s_int;
//	int	*d_int;
	size_t	len;

	d_str = s_str + 2;
	len = 5;
	fn_test("Manejo de strings: la direccion de dest es MAYOR que src", "s", d_str, s_str, len);

	return (0);
}

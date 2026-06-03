#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	fn_test(char *test_name, void *p, char type)
{
	t_list	*res;

	printf("\n--- TEST: %s ----\n", test_name);
	printf("\t* Dirección del puntero pasado: %p\n", p);
	
	res = ft_lstnew(p);
	if (!res)
	{
		printf("\t[ERROR]: ft_lstnew() ha devuelto NULL\n");
		return ;
	}
	
	if (res->content == NULL)
		printf("\t* Valor de res->content: NULL\n");
	else if (type == 'i') // Si es un entero
		printf("\t* Valor de res->content: %d\n", *(int *)res->content);
	else if (type == 'c') // Si es un char
		printf("\t* Valor de res->content: %c\n", *(char *)res->content);

	free(res);
}

int	main(void)
{
	int		*n;
	char	*c;

	n = malloc(sizeof(int));
	if (!n)
	{
		printf("Error de malloc en 'n'\n");
		return (1);
	}
	*n = 42;
	fn_test("Paso de un numero entero como contenido", n, 'i');

	c = malloc(sizeof(char));
	if (!c)
	{
		free(n);
		printf("Error de malloc en 'c'\n");
		return (1);
	}
	*c = 'a';
	fn_test("Paso de un char como contenido", c, 'c');

	fn_test("Paso de NULL como contenido", NULL, 'n');

	free(n);
	free(c);
	return (0);
}

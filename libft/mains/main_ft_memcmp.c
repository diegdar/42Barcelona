#include "libft.h"
#include <stdio.h>

void	f_print_result(int result)
{
	if(result == 0)
		printf("la variable 1 y 2 son iguales\n\n");
	else if(result > 0)
		printf("la variable 1 es mayor a la 2\n\n");
	else
		printf("La variable 1 es menor a  la 2\n\n");		
}

int	main(void)
{
	char	*p1;
	char	*p2;
	char	*p3;
	int		result;
	size_t	n;

	p1 = "luis";
	p2 = "luisa";
	p3 = "luismi";

	printf(">>v1 y v2 DEBERIAN ser iguales hasta el byte 4\n");
	n = 4;
	result = ft_memcmp(p1, p2, n);
	printf("**valor de p1:%.*s\n", (int)n, p1);
	printf("**valor de p2:%.*s\n", (int)n,  p2);
	f_print_result(result);	


	printf(">>v1 DEBERIA ser menor a v2 hasta el byte 5\n");
	n = 5;
	result = ft_memcmp(p1, p2, n);
	printf("**valor de p1:%.*s\n", (int)n, p1);
	printf("**valor de p2:%.*s\n", (int)n,  p2);
	f_print_result(result);
	
	printf(">>v1 DEBERIA ser mayor a v2 hasta el byte 5\n");
	n = 5;
	result = ft_memcmp(p3, p2, 5);
	printf("**valor de p3:%.*s\n", (int)n, p3);
	printf("**valor de p2:%.*s\n", (int)n,  p2);
	f_print_result(result);
	return (0);
}

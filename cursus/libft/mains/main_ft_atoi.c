#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	f_print_result(const char *str, int ft_result, int result_oficial)
{
	if (ft_result != result_oficial)
	{
		printf("!!❌ LOS VALORES DE LA FN OFICIAL Y LA MIA NO COINCIDEN!!:\n");
		printf("**valor del string : %s\n", str);
		printf("-valor devuelto por atoi(): %d\n", result_oficial);
		printf("-valor devuelto por ft_atoi(): %d\n", ft_result);
	}
	else
	{
		printf("✅LOS VALORES COINDICEN CORRECTAMENTE:\n");
		printf("**valor del string : %s\n", str);
		printf("-valor devuelto por atoi(): %d\n", result_oficial);
		printf("-valor devuelto por ft_atoi(): %d\n", ft_result);
	}
}

int	main(void)
{
	const char	*str;
	int		ft_result;
	int		result_oficial;

	printf("\n\n\n--------- PRUEBAS DE MAIN ------------\n\n");

	str = "42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);
	
	printf("\n>>Numeros al inicio y letras al final\n");
	str = "42abc";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);
	
	printf("\n>>Numeros al inicio y al final con letras en medio\n");
	str = "42abc24";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	printf("\n>>caracteres antes de numeros\n");
	str = "abc42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);	
	
	printf("\n>>Que pasa con un espacio entre numeros: '42 24'\n");
	str = "42 24";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);
	
	printf("\n>>Paso de caracteres no imprimibles  antes de un numero\n");
	str = " \t\n\f\r42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	printf("\n>>DEBERIA mostrar numeros negativos\n");
	str = "-42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	printf("\n>>DEBERIA devolver 42 cuando se le pasa '+42'\n");
	str = "+42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	printf("\n>>Que pasa si hay 2 signos negativos '--'?\n");
	str = "--42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	printf("\n>>Que pasa si hay signo negativo y positivo antes de un numero '+-'?\n");
	str = "+-42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	printf("\n>>Que pasa si hay signo positivo y negativo antes de un numero '+-'?\n");
	str = "+-42";
	printf("\n>>Que pasa si hay signo positivo y negtivo antes de un numero '+-'?\n");
	str = "+-42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);
	printf("\n>>Que pasa si hay signo positivo y negtivo antes de un numero '+-'?\n");
	str = "+-42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);
	
	printf("\n>>DEBERIA devolver 42 cuando se le pasa '+42'\n");
	str = "+42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	printf("\n>>Que pasa si pasamos un valor mas alla del maximo de un INT?\n");
	str = "2147483648";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	printf("\n>>Que pasa si pasamos un valor mas alla del minimo de un INT?\n");
	str = "-2147483649";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	printf("\n>>Que pasa si pasamos solo espacios "   "\n");
	str = "42";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);
	
	printf("\n>>Que pasa si pasamos solo '-0'\n");
	str = "-0";
	ft_result = ft_atoi(str);
	result_oficial = atoi(str);
	f_print_result(str, ft_result, result_oficial);

	return (0);
}

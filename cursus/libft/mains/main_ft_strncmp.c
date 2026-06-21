#include <stdio.h>
#include "libft.h"

static void	ft_printoutput(char *v1, char *v2, int out, size_t n)
{
	if (out == 0)
		printf("**El v1(%s) y v2(%s) son iguales comparando los primeros %zu caracteres\n", v1, v2, n);
	else if (out > 1)
		printf("**El v1(%s) es mayor a v2(%s) (esta por delante en ASCII) comparando los primero %zu caracteres\n" , v1, v2, n);
	else
		printf("**v1(%s) es menor a v2(%s) (esta por detras en ASCII) comparando los primeros %zu caracteres\n", v1, v2, n);
}

int	main(void)
{
	char	*s1 = "bcd";
	char	*s2 = "bce";
	char	*s3 = "abcd";
	char	*s4 = "abcf";
	int	out;
	size_t 	n;
	
	//v1 y v2 son iguales hasta el 2do caracter
	n = 2;
	out = ft_strncmp(s1,  s2, n);
	ft_printoutput(s1, s2, out, n);

	//v1 es menor a v2 compando hasta el 3er caracter
	n = 3;
	out = ft_strncmp(s1, s2, n);
	ft_printoutput(s1, s2, out, n);

	//v1 es mayor a v2 
	n = 4;
	out = ft_strncmp(s4,  s3, n);
	ft_printoutput(s4, s3, out, n);
	return (0);
}

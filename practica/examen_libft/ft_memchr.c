/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:35:18 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/18 19:33:26 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

//---- PRUEBAS ------------------
#include <stdio.h>
#include <string.h>

void	test_fn(char	*test_name, const void *s, int c, size_t n)
{
	char	*res;

	printf("\n--- TEST: %s ---", test_name);
	printf("\n\t*Valor de n: %zu bytes", n);

	res = ft_memchr(s, c, n);
	if (!res)
	{
		printf("la fun() ha devuelto: NULL");
		return ;
	}

	printf("\n\t**inicio de s: %p", s);
	printf("\n\t**original_fn: %p | my_fn: %p\n", memchr(s, c, n), ft_memchr(s, c, n));

}

int	main(void)
{
	char	*s1 = "hola mundo";
	int	c1 = 'o';
	size_t	n1 = 10;
	test_fn("Buscar dentro de un string", s1, c1, n1);

	char	*s2 = "42\0Barcelona";
	int	c2 = 'o';
	size_t	n2 = 12;
	test_fn("el valor '/\\0' dentro de un string ", s2, c2, n2);

	int	arr1[4] = {10, 24, 15, 28};
	int	num1 = 24;
	test_fn("Buscar dentro de un array de int", arr1, num1, sizeof(arr1));

	char	arr2[] = {9, 24, 15, 77};
	int	num2 = 15;
	test_fn("Buscar dentro de un array de chars", arr2, num2, sizeof(arr2));

	return (0);
}

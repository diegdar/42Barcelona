/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:07:31 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/18 17:35:05 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < (int)n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

//---- PRUEBAS ------------------
#include <stdio.h>

void	test_fn(char	*test_name, const char *s1, const char *s2, size_t n)
{
	printf("\n--- TEST: %s ---", test_name);
	printf("\n\t*Valor de s1: %s", s1);
	printf("\n\t*Valor de s2: %s", s2);
	printf("\n\t*Valor de n: %zu", n);

	printf("\n\t**Valor devuelto por fn(): %d\n ", ft_strncmp(s1, s2, n));

}

int	main(void)
{
	char	*s1;
	char	*s2;
	size_t	n;

	s1 = "luis";
	s2 = "luis";
	n = 4;
	test_fn("s1 y s2 deberian ser iguales teniendo ambos los mismo caracteres", s1, s2, n);

	s1 = "luis";
	s2 = "luisa";
	n = 4;
	test_fn("s1 y s2 deberian ser iguales a pesar de que el ultimo caracter es diferente por n= 4", s1, s2, n);

	s1 = "luismi";
	s2 = "luisa";
	n = 5;
	test_fn("s1 deberia ser mayor a s2", s1, s2, n);

	return (0);
}

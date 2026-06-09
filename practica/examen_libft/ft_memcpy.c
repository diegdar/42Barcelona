/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:58:45 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/09 18:47:25 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// ---- PRUEBAS ------
#include <stdio.h>
#include <stdlib.h>

void	fn_test(char *test_name, char *src, size_t n)
{
	char	res[20];

	printf("\n--- TEST: %s ---", test_name);
	printf("\n*Valor de s: %s", src);
	ft_memcpy(res, src, n);
	printf("\n*Valor devuelvo por ft_fn: %s \n", res);
}

int	main(void)
{
	char	*src = "hola mundo";
	size_t	n = 10;

	fn_test("copia todo src", src, n);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:00:18 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/18 16:37:17 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
 
char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == c)
			return (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

//---- PRUEBAS ------------------
#include <stdio.h>

void	test_fn(char	*test_name, const char *s, int c)
{
	char	*res;

	printf("\n--- TEST: %s ---", test_name);
	printf("\n\t*Valor de s: %s", s);
	printf("\n\t*Valor de c: %c", c);

	res = ft_strchr(s, c);
	if (!res)
	{
		printf("la fun() ha devuelto: NULL");
		return ;
	}

	printf("\n\t**Valor devuelto por fn(): %s\n ", res);

}

int	main(void)
{
	char	*s;
	int	c;

	s = "hola mundo";
	c = 'o';
	test_fn("Debe devolver el puntero en la posicion 1 del string", s, c);

	return (0);
}

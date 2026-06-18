/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:38:34 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/18 17:06:19 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strlen(char *s)
{
	int	i;

	i =0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	s = s + len - 1;
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		if (*s == '\0')
			break ;
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

	res = ft_strrchr(s, c);
	if (!res)
	{
		printf("\n\t***la fun() ha devuelto: NULL");
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
	test_fn("Debe devolver el puntero en la posicion 0 del string", s, c);

	return (0);
}

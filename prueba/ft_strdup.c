/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:56:08 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/09 16:29:39 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	copy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// ----- PRUEBAS -------

#include <stdio.h>
#include <stdlib.h>

void	strlen_test(char *test_name, char *s)
{
	printf("\n--- TEST: %s ---", test_name);
	printf("\nValor de s %s ---", s);
	printf("\nValor devuelvo por ft_fn %s \n", ft_strdup(s));
}

int	main(void)
{
//ft_strlen
	char	*s;

	s = "hola mundo";
	strlen_test("\nPaso de una cadena", s);

	return (0);
}

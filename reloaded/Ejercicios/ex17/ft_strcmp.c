/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:07:13 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/18 20:15:25 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>

int ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*s1 = NULL;
	char	*s2 = NULL;
	int	res;

	s1 = "lola";
	s2 = "lala";	
	res = ft_strcmp(s1, s2);
	if (res > 0)
		printf("s1 es mayor a s2 (esta despues en ascii)");
	else if(res < 0)
		printf("s1 es menor a s2 (esta antes en ascii)");
	else 
		printf("s1 y s2 son iguales");
	return (0);
}*/

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

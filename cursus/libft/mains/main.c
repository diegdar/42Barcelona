/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:35:13 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/30 20:42:43 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
# include <stddef.h>

int	main(int argc, char **argv)
{
	int		result;

	if (argc < 2)
	{
		printf("Se debe pasar almenos 1 argumento");
		return (1);
	}
	result = ft_isalpha(*argv[1]);
	printf("Resultado de ft_isalpha: %d\n", result);
	result = ft_isdigit(*argv[1]);
	printf("Resultado de ft_isdigit; %d\n", result);
	result = ft_isalnum(*argv[1]);
	printf("Resultado de ft_isalnum; %d\n", result);
	result = ft_isascii(*argv[1]);
	printf("Resultado de ft_isascii; %d\n", result);
	result = ft_isprint(*argv[1]);
	printf("Resultado de ft_isprint; %d\n", result);
	result = ft_strlen(argv[1]);
	printf("Resultado de ft_strlen; %d\n", result);
	
//ft_memset
	char	buffer[10];
	int		len;
	int		casted_value;

	casted_value = (int)argv[1][0];
	len = 7;
	ft_memset(buffer, casted_value, len);
	buffer[10] = '\0'; //cerramos el string con nulo
	printf("Resultado de ft_memset; %s\n", buffer);
//ft_bzero
	ft_bzero(buffer, len);
	printf("Resultado de ft_bzero; %s\n", buffer);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:21:44 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/08 10:05:41 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	res_ft;
	int	res_orig
;
	ft_printf("\n--TEST: impresion sin tipo de dato:--\n");
	res_ft = ft_printf("\t*ft_printf: esto hace parte de format\n");
	res_orig = printf("\t*printf:    esto hace parte de format\n");
	printf("**Retornos -> ft: %d | orig: %d\n", res_ft, res_orig);

	ft_printf("\n--TEST: impresion de un char 'c':--\n");
	res_ft = ft_printf("\t*ft_printf: '%c'\n", 'A');
	res_orig = printf("\t*printf:    '%c'\n", 'A');
	printf("**Retornos -> ft: %d | orig: %d\n", res_ft, res_orig);

	ft_printf("\n--TEST: impresion de un string 's':--\n");
	res_ft = ft_printf("\t*ft_printf: '%s'\n", "hello");
	res_orig = printf("\t*printf:    '%s'\n", "hello");
	printf("**Retornos -> ft: %d | orig: %d\n", res_ft, res_orig);

	ft_printf("\n--TEST: impresion de un puntero 'p':--\n");
	res_ft = ft_printf("\t*ft_printf: '%p'\n", "hello");
	res_orig = printf("\t*printf:    '%p'\n", "hello");
	printf("**Retornos -> ft: %d | orig: %d\n", res_ft, res_orig);
	return (0);
}

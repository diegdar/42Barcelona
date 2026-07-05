/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:21:44 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/05 19:08:40 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	res_ft;
	int	res_orig;

	res_ft = ft_printf("Mi printf: %c\n", 'A');
	res_orig = printf("Original: %c\n", 'A');

	printf("Retornos -> ft: %d | orig: %d\n", res_ft, res_orig);

	return (0);
}

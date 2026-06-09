/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:04:30 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/23 10:13:49 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_abs.h"

int	main(void)
{
	int	n1;
	int	n2;

	n1 = -5;
	n2 = 10;
	printf("Abs de %d es %d\n", n1, ABS(n1));
	printf("Abs de %d es %d\n", n2, ABS(n2));
	printf("Abs de operacion es %d\n", ABS(5 - 20));
	return (0);
}

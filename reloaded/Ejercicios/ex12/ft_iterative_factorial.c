/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:10:24 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/16 18:14:45 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>

int ft_iterative_factorial(int nb);

int	main(void)
{
	int	result;

	result = ft_iterative_factorial(4);
	printf("%d", result);
	return (0);
}*/

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0 || nb > 12)
		return (0);
	result = 1;
	while (nb > 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:12:24 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/17 10:16:45 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>

int ft_recursive_factorial(int nb);

int	main(void)
{
	int	res;

	res = ft_recursive_factorial(4);
	printf("%d", res);
	return (0);
}*/

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

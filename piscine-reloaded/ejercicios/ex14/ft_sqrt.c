/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:01:24 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/20 17:42:18 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
int ft_sqrt(int nb);

int	main(void)
{
	int	res;
	res = ft_sqrt(-9);
	printf("%d", res);
	return (0);	
}*/

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 2;
	while (i <= nb / i && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

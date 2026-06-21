/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:50:16 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/23 18:38:51 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

void	ft_printduplicate(int num)
{
	printf("%d\n", (num * num));
}

int	main(void)
{
	int	tab []= {2, 3, 1};
	int	length;
	
	length 	= sizeof(tab) / sizeof(tab[0]);
	ft_foreach(tab, length, &ft_printduplicate);
	return (0);
}
*/
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

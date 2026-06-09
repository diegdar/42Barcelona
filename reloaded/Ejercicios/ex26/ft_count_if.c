/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:40:01 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/23 19:24:03 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>

int	ft_count_if(char **tab, int (*f)(char*));

int	ft_count_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])	
		i++; 
	return (i);	
}

int	main(void)
{
	char	*tab[] = {"hola", "a", "mundo", "b", 0};
	int	res = ft_count_if(tab, &ft_count_chars);
	printf ("%d", res);
	return (0);
}
*/

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

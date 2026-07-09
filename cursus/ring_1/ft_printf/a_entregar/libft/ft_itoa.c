/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:27:48 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/02 12:48:05 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

size_t	ft_intlen(long n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*strnum;
	size_t	size;
	long	n_long;

	n_long = n;
	if (n_long < 0)
		n_long = -n_long;
	size = ft_intlen(n_long);
	if (n < 0)
		size++;
	strnum = malloc(sizeof(char) * (size + 1));
	if (!strnum)
		return (NULL);
	strnum[size] = '\0';
	while (size--)
	{
		strnum[size] = (n_long % 10) + '0';
		n_long /= 10;
	}
	if (n < 0)
	{
		strnum[0] = '-';
		return (strnum);
	}
	return (strnum);
}

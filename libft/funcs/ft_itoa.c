/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:27:48 by dichacon          #+#    #+#             */
/*   Updated: 2026/05/27 19:18:52 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static long	calculate_size(long n)
{
	long	count;

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

static void	convert_int_to_str(long n_long, char *end)
{
	while (n_long > 0)
	{
		*end-- = (n_long % 10) + '0';
		n_long /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*strnum;
	size_t	size;
	char	*end;
	size_t	is_negative;
	long	n_long;

	size = 0;
	n_long = n;
	is_negative = (n < 0);
	if (is_negative)
		n_long = -n_long;
	size += calculate_size(n_long) + is_negative;
	strnum = malloc(sizeof(char) * (size + 1));
	strnum[size] = '\0';
	if (n_long == 0)
	{
		strnum[0] = '0';
		return (strnum);
	}
	end = strnum + size - 1;
	convert_int_to_str(n_long, end);
	if (is_negative)
		strnum[0] = '-';
	return (strnum);
}

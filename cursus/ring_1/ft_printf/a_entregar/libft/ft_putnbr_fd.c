/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:38:22 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/02 16:18:31 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

static long	get_divisor(long n_long)
{
	long	divisor;

	divisor = 1;
	while (n_long / divisor >= 10)
	{
		divisor *= 10;
	}
	return (divisor);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	size_t	divisor;
	long	n_long;

	n_long = n;
	if (n < 0)
	{
		n_long = -n_long;
		write(fd, "-", 1);
	}
	divisor = get_divisor(n_long);
	while (divisor > 0)
	{
		digit = (n_long / divisor) % 10 + '0';
		write(fd, &digit, 1);
		divisor /= 10;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:54:30 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/20 20:03:49 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

/*
#include <unistd.h>
void	ft_putnbr(int n)
{
	char	digit;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int		*ft_range(int min, int max);

int	main(void)
{
	int	min;
	int	max;
	int	*nums;
	int	i;

	min = 7;
	max = 10;
	nums = ft_range(min, max);
	if (nums)
	{
		i = 0;
		while (i < max - min)
		{
			ft_putnbr(nums[i]);
			i++;
		}
	}
	return (0);
}
*/
int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	range = malloc(sizeof(*range) * size);
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

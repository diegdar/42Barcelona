/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:00:24 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/17 13:25:33 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* #include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	else
		ft_putchar('P');
}

// int	main(void)
// {
// 	ft_is_negative(-2147483647);
// 	return (0);
// }

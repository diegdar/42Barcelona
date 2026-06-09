/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 19:10:20 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/09 19:25:45 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int putchar(int c)
{
	write(1, &c, 1);
}

void ft_print_numbers(void)
{
	char	c;

	c = 0;
	while (c <= '9')
	{
		putchar(c);
		c++;
	}
}

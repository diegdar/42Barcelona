/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:24:18 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/09 14:26:43 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	process_int(long long num)
{
	int chars_num;
	char	c;

	chars_num = 0;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		chars_num++;
	}

	if (num >= 10)
		chars_num += process_int(num / 10);
	c = (num % 10) + '0';
	ft_putchar(c);
	chars_num++;
	return (chars_num);
}

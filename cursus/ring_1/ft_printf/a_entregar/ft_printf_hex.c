/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:59:48 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/08 17:50:21 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	get_hex(unsigned long long num, char format)
{
	char *base;
	int	chars_num;

	chars_num = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		chars_num += get_hex(num / 16, format);
	ft_putchar(base[num % 16]);
	chars_num++;
	return (chars_num);
}

int	process_ptr(va_list *args)
{
	unsigned long long ptr;
	int			chars_num;

	chars_num = 0;
	ptr = va_arg(*args, unsigned long long);
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	chars_num += 2;
	chars_num += get_hex(ptr, 'x');
	return (chars_num);
}

int	process_hex(va_list *args, char const type)
{
	int			chars_num;
	unsigned long long	num;

	chars_num = 0;
	num = va_arg(*args, unsigned int);
	chars_num += get_hex(num, type);
	return (chars_num);
}

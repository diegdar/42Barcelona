/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:05:15 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/19 12:59:25 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	parser_type(char const type, va_list *args)
{
	long long	num;

	if (type == 'c')
		return (print_char(args));
	else if (type == 's')
		return (print_str(args));
	else if (type == 'p')
		return (print_ptr(args));
	else if (type == 'x' || type == 'X')
		return (print_hex(args, type));
	else if (type == '%')
		return (ft_putchar('%'), 1);
	else if (type == 'd' || type == 'i')
	{
		num = va_arg(*args, int);
		return (print_int(num));
	}
	else if (type == 'u')
	{
		num = va_arg(*args, unsigned int);
		return (print_int(num));
	}
	else
		return (-1);
}

int	loop_format(char const *format, va_list *args)
{
	int	chars_num;
	int	i;

	chars_num = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			chars_num += parser_type(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			chars_num++;
		}
		i++;
	}
	return (chars_num);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		chars_num;

	if (!format)
		return (-1);
	va_start(args, format);
	chars_num = loop_format(format, &args);
	va_end(args);
	return (chars_num);
}

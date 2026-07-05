/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:05:15 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/05 19:13:31 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	parser_type(char const type, va_list *args)
{
	if (type == 'c')
		return (process_char(args));
/*	else if (type == 's')i
		return (process_string);*/
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	num_chars;

	if (!format)
		return (-1);

	va_start(args, format);
	num_chars = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			num_chars += parser_type(format[i + 1], &args);
		else
		{
			write(1, &format[i], 1);
			num_chars++;
		}
		i++;
	}

	va_end(args);
	return (num_chars);
}

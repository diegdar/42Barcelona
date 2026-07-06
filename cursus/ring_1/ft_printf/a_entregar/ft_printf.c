/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:05:15 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/06 16:53:08 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	parser_type(char const type, va_list *args)
{
	if (type == 'c')
		return (process_char(args));
	else if (type == 's')
		return (process_string(args));
	else
		return (-1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	chars_num;

	if (!format)
		return (-1);

	va_start(args, format);
	chars_num = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			chars_num += parser_type(format[i + 1], &args);
			i++;
		}
		else
		{			write(1, &format[i], 1);
			chars_num++;
		}
		i++;
	}

	va_end(args);
	return (chars_num);
}

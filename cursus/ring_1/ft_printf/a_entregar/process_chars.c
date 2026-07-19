/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c    #include "ft_printf.h"
                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:04:13 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/08 18:07:44 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	ft_putchar(c);
	return (1);
}

int	print_str(va_list *args)
{
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(s);
	return (ft_strlen(s));
}

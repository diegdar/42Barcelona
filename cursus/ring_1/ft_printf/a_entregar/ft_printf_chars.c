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

int	process_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	ft_putchar(c);
	return (1); 
}

int	process_str(va_list *args)
{
	char	*s;
	int	i;

	s = va_arg(*args, char *);
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	process_percent()
{
	ft_putchar('%');
	return (1);
}

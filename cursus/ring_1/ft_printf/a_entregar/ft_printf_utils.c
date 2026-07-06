/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:05:37 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/06 19:21:08 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putchar(char c)
{
	if (!c)
		return ;
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++; 
	}
}

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


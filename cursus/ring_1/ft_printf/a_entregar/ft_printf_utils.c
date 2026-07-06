/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:05:37 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/06 16:54:56 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	process_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	write(1, &c, 1);
	return (1); 
}

int	process_string(va_list *args)
{
	char	*s;
	int	i;

	s = va_arg(*args, char *);
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}


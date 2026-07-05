/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:05:37 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/05 19:51:56 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	process_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	write(1, &c, 1);
	return (1); 
}
/*
size_t	process_string(va_list *args)
{
	int	s;

	s = (char)va_arg(*arg, int);

}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:24:18 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/09 05:48:46 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	process_int(va_list *args)
{
	long	num;
	char	*num_char;

	num = va_arg(*args, int);
	num_char = ft_itoa(num);
	ft_putstr(num_char);
	return (ft_strlen(num_char));
}

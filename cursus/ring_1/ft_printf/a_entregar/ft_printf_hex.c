/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:59:48 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/06 19:37:24 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*get_hex(unsigned long long num)
{
	

	return ;
}

int	process_ptr(va_list *args)
{
	int			chars_num;
	unsigned long long ptr;

	ptr = va_arg(*args, unsigned long long);
	if (ptr == 0)
		return (0);
	

	return (chars_num);
}

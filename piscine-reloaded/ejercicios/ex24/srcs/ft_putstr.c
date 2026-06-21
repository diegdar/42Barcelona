/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:47:40 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/23 17:09:12 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

/*#include <unistd.h>

void	ft_putstr(char *str);

int	main(void)
{	
	char *str = NULL;

	str = "hola mundo";
	ft_putstr(str);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

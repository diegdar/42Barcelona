/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:12:24 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/17 10:16:45 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

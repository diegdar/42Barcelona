/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:05:15 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/21 16:59:14 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char var1 = 102;
	short int var2 = 2024;
	int var3 = 95;
	long int var4 = 212;
	long long int var5 = 1200L;
	printf("%hhd %hd %d %ld %lld", var1, var2, var3, var4, var5);

	return (0);
}

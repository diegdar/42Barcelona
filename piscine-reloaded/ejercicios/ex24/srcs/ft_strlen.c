/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:09:54 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/23 17:10:10 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
int	ft_strlen(char *str);

int	main(void)
{
	char *str = NULL;
	int	res;

	str = "hello world";
	res = ft_strlen(str);
	printf("%d", res);
	return (0);
}*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

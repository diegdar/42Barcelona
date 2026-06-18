/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:53:10 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/09 15:51:56 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	*ptr;

	if (min >= max)
		return (NULL);
	arr = malloc((sizeof(int) * (max - min)));
	if (!arr)
		return (NULL);
	ptr = arr;
	while (min < max)
	{
		*ptr = min++;
		ptr++;
	}
	return (arr);
}

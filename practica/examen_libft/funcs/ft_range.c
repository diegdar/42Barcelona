/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:52:51 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/17 21:08:42 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*arr;
	int	i;
	int	size;

	if (start >= end)
		return (NULL);
	size = end - start;
	if (size < 0)
		size *= -1;
	arr = malloc(sizeof(int) * (size + 1));
	if(!arr)
		return (NULL);
	i = 0;
	while (i <= size)
		arr[i++] = start++;
	return (arr);
}

//PRUEBAS:
#include <stdio.h>

void	test_fn(char	*test_name, int start, int end)
{
	int	*res;
	int	i;
	int	size;

	printf("\n--- TEST: %s---", test_name);
	printf("\n\t*Valor de start: %d", start);
	printf("\n\t*Valor de end: %d", end);
	res = ft_range(start, end);
	if (!res)
	{
		printf("\n\t**Valor devuelto por la fn(): NULL\n");
		return ;
	}

	printf("\n\t**Valor devuelto por la fn(): ");
	size = end - start + 1;
	i = 0;
	while (i < size)
	{
		printf("%d", res[i]);
		if (res[i] != end)
		printf(", ");
		i++;
	}
	printf("\n");

	free(res);
}

int	main(void)
{
	int	start;
	int	end;

	start = 1;
	end = 5;
	test_fn("start siendo menor a end y siendo ambos positivos", start, end);

	start = 3;
	end = 1;
	test_fn("start siendo mayor a end y siendo ambos positivos", start, end);

	start = -5;
	end = -1;
	test_fn("start siendo menor a end y siendo ambos negativos", start, end);

	start = 3;
	end = -1;
	test_fn("start siendo negativo y mayor a end(y este ultimo es positivo)", start, end);

	return (0);
}


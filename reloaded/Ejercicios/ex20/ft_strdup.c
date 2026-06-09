/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:54:30 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/20 20:03:49 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

/*
char	*ft_strdup(char *src);

int	main(void)
{
	char	*src;
	char	*copy;

	src = "hello";
	copy = ft_strdup(src);
	if (copy)
		ft_putstr(copy);
	free(copy);
	copy = NULL;
	return (0);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putchar(char c);

void	(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(src);
	dest = malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

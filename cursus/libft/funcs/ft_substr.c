/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:16:01 by dichacon          #+#    #+#             */
/*   Updated: 2026/05/19 21:10:55 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;
	size_t	size;

	s_len = ft_strlen(s);
	if (start > s_len)
		size = 1;
	else if ((start + len) > s_len)
		size = s_len - start + 1;
	else
		size = (sizeof(char) * len) + 1;
	sub = malloc(size);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i] && i < size - 1)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

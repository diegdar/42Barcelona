/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:26:05 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/24 19:39:28 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
		i++
	return (i);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] || i < n)
	{
		dup[i] = s[i]
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

void	ft_copy_data(char *dest, const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*s1)
	{
		dest[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		dest[i] = *s2;
		s2++;
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin_with_free(char const *buffer, char const *storage)
{
	char	*merger;

	if (!buffer && !storage)
		return (NULL);
	if (!storage)
		storage = ft_strndup("", 1);
	if(!storage)
		return (NULL);
	merger = malloc(sizeof(merger) * ((ft_strlen(buffer) + ft_strlen(storage) + 1));
	if (!merger)
	{
		free(storage);
		return (NULL);
	}
	ft_copy_data(merger, buffer, storage);
	free(storage);
	return (merger);
}

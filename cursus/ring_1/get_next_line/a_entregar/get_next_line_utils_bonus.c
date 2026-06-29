/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:26:05 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/29 19:45:32 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
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
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
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

void	ft_copy_data(char *dest, const char *storage, const char *buffer)
{
	size_t	i;

	i = 0;
	while (*storage)
	{
		dest[i] = *storage;
		storage++;
		i++;
	}
	while (*buffer)
	{
		dest[i] = *buffer;
		buffer++;
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin_with_free(char const *buffer, char *storage)
{
	char	*merger;
	size_t	size;

	if (!buffer && !storage)
		return (NULL);
	if (!storage)
		storage = ft_strndup("", 0);
	if (!storage)
		return (NULL);
	size = ft_strlen(buffer) + ft_strlen(storage) + 1;
	merger = malloc(sizeof(char) * size);
	if (!merger)
	{
		free(storage);
		return (NULL);
	}
	ft_copy_data(merger, storage, buffer);
	free(storage);
	return (merger);
}

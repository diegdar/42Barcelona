/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:26:05 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/03 18:59:03 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
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

char	*ft_strjoin(char const *buffer, char *storage, size_t size)
{
	char	*new_storage;

	if (!buffer && !storage)
		return (NULL);
	if (!storage)
		storage = ft_strndup("", 0);
	new_storage = malloc(sizeof(char) * (size + 1));
	if (!new_storage)
	{
		free(storage);
		return (NULL);
	}
	ft_copy_data(new_storage, storage, buffer);
	free(storage);
	return (new_storage);
}

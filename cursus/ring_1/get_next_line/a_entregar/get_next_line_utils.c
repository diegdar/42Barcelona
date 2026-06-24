/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:26:05 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/24 12:40:06 by dichacon         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*merger;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	merger = malloc(sizeof(merger) * ((s1_len + s2_len) + 1));
	if (!merger)
		return (NULL);
	i = 0;
	while (*s1)
	{
		merger[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		merger[i] = *s2;
		s2++;
		i++;
	}
	merger[i] = '\0';
	return (merger);
}

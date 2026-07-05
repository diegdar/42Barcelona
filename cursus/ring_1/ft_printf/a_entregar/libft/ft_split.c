/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:15:47 by dichacon          #+#    #+#             */
/*   Updated: 2026/05/26 17:37:50 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static void	free_all(char *arr[])
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

static size_t	count_strs(const char *s, char c)
{
	size_t	found;
	size_t	count;

	found = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !found)
		{
			found = 1;
			count++;
		}
		if (*s == c)
			found = 0;
		s++;
	}
	return (count);
}

static char	*add_str(const char *start, const char *end)
{
	size_t	str_size;
	char	*str;

	str = NULL;
	str_size = (end - start) + 1;
	str = malloc(sizeof(char) * str_size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, start, str_size);
	return (str);
}

static char	**fill_array(char **arr, const char *s, char c)
{
	size_t		i;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s && *s != c)
			s++;
		arr[i] = add_str(start, s);
		if (!arr[i])
		{
			free_all(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	arr_size;

	if (!s)
		return (NULL);
	arr_size = count_strs(s, c) + 1;
	arr = malloc(sizeof(char *) * arr_size);
	if (!arr)
		return (NULL);
	if (!fill_array(arr, s, c))
		return (NULL);
	return (arr);
}

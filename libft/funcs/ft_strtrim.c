/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:18:16 by dichacon          #+#    #+#             */
/*   Updated: 2026/05/22 19:53:12 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
//	#include <stdio.h>

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*result;
	char	*start_s;
	char	*end_s;
	size_t	size;

	if (!s || !set)
		return (NULL);
	start_s = (char *)s;
	while (*start_s && is_in_set(*start_s, set))
		start_s++;
	if (!*start_s)
		return (ft_strdup(start_s));
	end_s = (char *)start_s + ft_strlen(start_s) - 1;
	while (is_in_set(*end_s, set) && start_s < end_s)
		end_s--;
	size = (end_s - start_s) + 1 + 1;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	ft_strlcpy(result, start_s, size);
	return (result);
}

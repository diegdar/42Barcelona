/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:04:14 by dichacon          #+#    #+#             */
/*   Updated: 2026/05/20 18:01:18 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*merger;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	merger = malloc(sizeof(char) * (s1_len + s2_len) + 1);
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

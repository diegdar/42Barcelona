/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:33:07 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/22 19:01:06 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	ssize_t	nrbytes;
	char	*buffer;
	char	*line;
	int	i;
	static int	j;
	static char	*storage;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nr_bytes = read(fd, buffer, BUFFER_SIZE);
	if (nr_bytes < 1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[nr_bytes] = '\0';
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (buffer);
		storage[j] = buffer[i];
		i++;
		j++;
	}

}

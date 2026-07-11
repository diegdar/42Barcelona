/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:33:07 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/11 18:01:43 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <unistd.h>

char	*cut_excess(char *storage)
{
	char	*new_storage;
	size_t	i;

	i = 0;
	while (storage[i] != '\n')
		i++;
	new_storage = ft_strndup(&storage[i + 1], ft_strlen(&storage[i + 1]));
	free(storage);
	storage = NULL;
	return (new_storage);
}

char	*read_buffer(int fd, char *storage, char *buffer)
{
	ssize_t	nr_bytes;
	size_t	size;

	nr_bytes = 1;
	size = ft_strlen(storage);
	while (nr_bytes > 0)
	{
		nr_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nr_bytes == -1)
			return (NULL);
		buffer[nr_bytes] = '\0';
		size = size + nr_bytes;
		storage = ft_strjoin(buffer, storage, size);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

char	*fill_storage(int fd, char *storage)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	storage = read_buffer(fd, storage, buffer);
	if (!storage)
	{
		free(buffer);
		buffer = NULL;
		free(storage);
		storage = NULL;
		return (NULL);
	}
	free(buffer);
	buffer = NULL;
	return (storage);
}

static char	*extract_line(char **storage)
{
	char	*line;
	char	*check_line;

	check_line = ft_strchr(*storage, '\n');
	if (check_line)
	{
		line = ft_strndup(*storage, check_line - *storage + 1);
		*storage = cut_excess(*storage);
	}
	else
	{
		line = ft_strndup(*storage, ft_strlen(*storage));
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = fill_storage(fd, storage[fd]);
	if (!storage[fd] || !*storage[fd])
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&storage[fd]));
}

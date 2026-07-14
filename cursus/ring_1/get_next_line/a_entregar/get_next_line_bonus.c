/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 12:05:18 by dichacon          #+#    #+#             */
/*   Updated: 2026/07/14 22:38:35 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*clean_storage(char **storage)
{
	free(*storage);
	*storage = NULL;
	return (NULL);
}

char	*read_buffer(int fd, char **storage, char *buffer)
{
	ssize_t	nr_bytes;
	char	*temp;

	if (ft_strchr(*storage, '\n'))
		return (*storage);
	nr_bytes = 1;
	while (nr_bytes > 0)
	{
		nr_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nr_bytes == -1)
			return (clean_storage(storage));
		if (nr_bytes == 0)
			break ;
		buffer[nr_bytes] = '\0';
		temp = ft_strjoin(*storage, buffer);
		if (!temp)
			return (clean_storage(storage));
		free(*storage);
		*storage = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*storage);
}

char	*fill_storage(int fd, char **storage)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (clean_storage(storage));
	*storage = read_buffer(fd, storage, buffer);
	free(buffer);
	return (*storage);
}

static char	*extract_line(char **storage)
{
	char	*line;
	char	*check_line;

	if (!*storage || !**storage)
		return (clean_storage(storage));
	check_line = ft_strchr(*storage, '\n');
	if (check_line)
	{
		line = ft_strndup(*storage, check_line - *storage + 1);
		if (!line)
			return (clean_storage(storage));
		*storage = cut_excess(*storage);
	}
	else
	{
		line = ft_strndup(*storage, ft_strlen(*storage));
		clean_storage(storage);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = fill_storage(fd, &storage[fd]);
	if (!storage[fd])
		return (NULL);
	return (extract_line(&storage[fd]));
}

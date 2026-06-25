/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:33:07 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/25 18:30:53 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>

char	*cut_excess(char *old_storage)
{
	char	*new_storage;
	size_t	i;

	i = 0;
	while (old_storage[i] != '\n')
		i++;
	new_storage = ft_strndup(&old_storage[i + 1], ft_strlen(&old_storage[i + 1]));
	free(old_storage);
	return (new_storage);
}

char	*fill_storage(int fd, char *storage)
{
	char	*buffer;
	ssize_t	nr_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nr_bytes = 1;
	while (ft_strchr(storage, '\n') == NULL && nr_bytes > 0)
	{
		nr_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nr_bytes] = '\0';
		storage = ft_strjoin_with_free(buffer, storage);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*check_line;
	size_t	line_len;
	static char	*storage;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = fill_storage(fd, storage);
	if (!storage || !*storage)
		return (NULL);
	check_line = ft_strchr(storage, '\n');
	if (check_line)
	{
		line_len = check_line - storage + 1;
		line = ft_strndup(storage, line_len);
		storage = cut_excess(storage);
	}
	else
	{
		line = ft_strndup(storage, ft_strlen(storage));
		free(storage);
		storage = NULL;
	}
	return (line);
}

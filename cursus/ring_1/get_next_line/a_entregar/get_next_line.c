/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:33:07 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/24 19:42:56 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>

void	cut_excess(char *old_storage)
{
	char	*new_storage;
	size_t	i;

	i = 0;
	while (old_storage[i] != '\n')
		i++;
	temp = ft_strndup(old_storage[i], ft_strlen(old_storage[i]);
	free(old_storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	ssize_t	nr_bytes;
	char	*buffer;
	char	*line;
	char	*check_line;
	size_t	line_len;
	static char	*storage;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
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
		storage = ft_str_join_and_free(buffer, storage);
	}
	free(buffer);
	if (!storage || *storage)
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
}

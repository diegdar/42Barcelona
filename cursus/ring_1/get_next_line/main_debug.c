#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc != 2)
	{
		printf("Uso: %s <archivo>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		printf("[%d] line = %p", i, (void *)line);
		if (line)
			printf(" -> \"%s\"", line);
		printf("\n");
		free(line);
		i++;
		if (!line)
			break ;
	}
	printf("\nLlamando otra vez después del EOF...\n");
	line = get_next_line(fd);
	printf("line = %p\n", (void *)line);
	free(line);

	close(fd);
	return (0);
}

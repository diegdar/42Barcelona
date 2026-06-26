#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("ERROR: al tratar abrir el archivo %s", argv[1]);
			return (1);
		}
	}
	else
	{
		fd = 0;
		printf("Leyendo desde la terminal...\n");
	}

	line = get_next_line(fd);
	while (line)
	{
		printf("Valor de line: '%s'", line);
		free(line);
		line = get_next_line(fd);
	}

	if (fd > 0)
		close(fd);

	return (0);
}

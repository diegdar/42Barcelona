#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

void	read_interleaved(int *fds, int count)
{
	char	*line;
	int		i;
	int		keep_reading;

	keep_reading = 1;
	while (keep_reading)
	{
		keep_reading = 0;
		i = 0;
		while (i < count)
		{
			line = get_next_line(fds[i]);
			if (line != NULL)
			{
				printf("\n[FD %d]: %s", fds[i], line);
				free(line);
				keep_reading = 1;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	fds[argc - 1]; 
	int fd_term;
	int	num_files;
	int	i;

	if (argc > 1)
	{
		num_files = argc - 1;
		i = 0;
		while (i < num_files)
		{
			fds[i] = open(argv[i + 1], O_RDONLY);
			if (fds[i] == -1)
				{
					printf("Error al tratar de abrir el fd '%d'", i + 1);
					return (1);
				}
			i++;
		}

		read_interleaved(fds, num_files);

		i = 0;
		while (i < num_files)
		{
			if (fds[i] > 0)
				close(fds[i]);
			i++;
		}
	}
	else
	{
		printf("Leyendo desde la terminal (Pulsa Ctrl+D para acabar)...\n");
		
		fd_term = 0;
		read_interleaved(&fd_term, 1);
	}
	return (0);
}

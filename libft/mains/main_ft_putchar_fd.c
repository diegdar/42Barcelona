#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	out[2];

	fd = open("ft_putchar_test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "Error al abrir el archivo\n", 26);
		return (1);
	}

	ft_putchar_fd('A', fd);

	/* Volver al inicio del archivo para poder leer */
	lseek(fd, 0, SEEK_SET);

	read(fd, out, 1);
	out[1] = '\0';

	printf("Contenido del archivo: '%s'\n", out);

	close(fd);
	return (0);
}

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	out[18];

	fd = open("ft_putstr_fd_test.txt", O_RDWR | O_CREAT, 0644);
	if (fd == -1)
	{
		write(2, "Error al abrir el archivo\n", 26);
		return (1);
	}

	ft_putstr_fd("Hola ft_putstr_fd", fd);

	/* Volver al inicio del archivo para poder leer */
	lseek(fd, 0, SEEK_SET);

	read(fd, out, 17);
	out[18] = '\0';

	printf("Contenido del archivo: '%s'\n", out);

	close(fd);
	return (0);
}

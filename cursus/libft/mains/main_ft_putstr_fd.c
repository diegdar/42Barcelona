#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	fn_test(char *test_name, char *s, size_t len)
{
	int	fd;
	char	buff[len + 1];//+ 1 para el '\0'
	size_t	read_bytes;

	printf("\n--- Test: %s ---", test_name);

	fd = open("ft_putendl_fd_test.txt", O_RDWR | O_CREAT |O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "Error al abrir el archivo\n", 26);
		return ;
	}

	ft_putstr_fd(s, fd);
	lseek(fd, 0, SEEK_SET);

	read_bytes =read(fd, buff, len);
	buff[read_bytes] = '\0';

	printf("\nContenido del archivo: '%s'\n", buff);

	close(fd);
}

int	main(void)
{
	char	*s;
	size_t	len;

	s = "La magia de C";
	len = ft_strlen(s);
	fn_test("Paso de un string con caracteres imprimibles", s, len);

	s = "";
	len = ft_strlen(s);
	fn_test("Paso de un string vacio", s, len);

	s = NULL;
	len = 1;
	fn_test("Paso de un valor NULL como string", s, len);

	return (0);
}

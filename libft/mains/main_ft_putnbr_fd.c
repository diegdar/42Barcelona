#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	fn_test(char	*test_name, int n, size_t len)
{
	int	fd;
	char	buff[len + 1];
	size_t	read_bytes;

	printf("\n--- TEST: %s ---", test_name);
	printf("\n\t*Valor de n: %d", n);

	fd = open("ft_putnbr_test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "\nError al abrir el archivo\n", 26);
		return ; 
	}

	ft_putnbr_fd(n, fd);
	lseek(fd, 0, SEEK_SET);
	read_bytes = read(fd, buff, len);
	buff[read_bytes] = '\0';

	printf("\n\t*Valor guardado en el buff: '%s'\n", buff);

	close(fd); 
}

int	main(void)
{
	int	n;
	size_t	len;

	n = 42;
	len = ft_strlen(ft_itoa(n));
	fn_test("Paso de un numero de 2 digitos positivos", n, len);

	n = 1234;
	len = ft_strlen(ft_itoa(n));
	fn_test("Paso de un numero de 4 digitos positivos", n, len);

	n = -42;
	len = ft_strlen(ft_itoa(n));
	fn_test("Paso de un numero de 2 digitos negativo", n, len);

	n = 0;
	len = ft_strlen(ft_itoa(n));
	fn_test("Paso del numero '0'", n, len)
;
	n = (int)(~0U >> 1);
	len = ft_strlen(ft_itoa(n));
	fn_test("Paso del valor MAXIMO de un int", n, len);

	n = (1 << 31);
	len = ft_strlen(ft_itoa(n));
	fn_test("Paso del valor MINIMO de un int", n, len);
	return (0);
}

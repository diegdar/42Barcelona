/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:13:08 by dichacon          #+#    #+#             */
/*   Updated: 2026/04/24 15:34:54 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 4096

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

int	validate_arguments(int argc)
{
	if (argc == 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Too many arguments.\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	ssize_t	nr_bytes;
	char	buffer[BUF_SIZE];
	int		is_validated;

	is_validated = validate_arguments(argc);
	if (is_validated)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return (1);
	}
	nr_bytes = read(fd, buffer, BUF_SIZE);
	while (nr_bytes > 0)
	{
		write(1, buffer, nr_bytes);
		nr_bytes = read(fd, buffer, BUF_SIZE);
	}
	close(fd);
	return (0);
}

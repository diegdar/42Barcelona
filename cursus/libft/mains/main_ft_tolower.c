#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Type: [upper letter to convet in lower]");
		return (1);
	}

	char	out = (char)ft_tolower(*argv[1]);
	printf("Output: %c", out);
	return (0);
}

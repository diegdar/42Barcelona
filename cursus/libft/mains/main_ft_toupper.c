#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{	
		printf("Type: [lower letter to convet in upper]");
		return (1);
	}
	
	char	out = (char)ft_toupper(*argv[1]);
	printf("Output: %c", out);
	return (0);
}

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

static void test_fn(const char *s, char *test_name)
{
	char	*copy1;
	char	*copy2;

	printf("\n----- Test: %s ----", test_name);
    copy1 = strdup(s);
	copy2 = ft_strdup(s);

    if (!copy1)
    {       
	    printf("copy1 devuelve un valor NULL");
        free(copy1);
        free(copy2);
        return ;
    }

    if (!copy2)
    {       
	    printf("copy2 devuelve un valor NULL");
        free(copy1);
        free(copy2);
        return ;
    }

	printf("\nString fuente> puntero: %p, valor: %s\n", s, s);

	printf("\n>> comportamiento de strdup():");
	printf("\nString copia> puntero: %p, valor: %s\n", copy1, copy1);

	printf("\n>> comportamiento de ft_strdup():");
	printf("\nString copia> puntero: %p, valor: %s\n", copy2, copy2);

    printf("\n ======== Fin del Test ==============");

    free(copy1);
    free(copy2);
} 

int	main(void)
{
	printf("\n=========================================");
	printf("\n       DEBUG FT_STRDUP - 42BARCELONA     ");
	printf("\n=========================================\n");

	char	*s;

	s = "bar";
	test_fn(s, "paso de un string de 3 bytes");

	s = "";
	test_fn(s, "Que pasa si se pasa un valor vacio?");

	printf("\n=========================================\n");
	return (0);
}

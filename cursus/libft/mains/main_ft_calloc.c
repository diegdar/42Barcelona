#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
** Esta función auxiliar comprueba si el bloque de memoria
** está realmente lleno de ceros.
*/
static int	check_zeros(void *p, size_t total_size)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)p;
	while (i < total_size)
	{
		if (ptr[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static void	test_calloc(size_t nmemb, size_t size, char *test_name)
{
	void	*p;
	size_t	total;

	total = nmemb * size;
	printf("\n--- Test: %s ---\n", test_name);
	printf("Parámetros: nmemb[%zu], size[%zu] (Total: %zu)\n", nmemb, size, total);
	
	p = ft_calloc(nmemb, size);
	
	/* 1. COMPROBACIÓN DE PUNTERO ÚNICO (Regla 42) */
	if (p == NULL)
	{
		printf("❌ ERROR: ft_calloc devolvió NULL.\n");
		printf("⚠️  Nota: El PDF exige un puntero único para tamaño 0.\n");
	}
	else
	{
		printf("✅ Puntero asignado: %p\n", p);
		
		/* 2. COMPROBACIÓN DE CONTENIDO (Solo si hay tamaño) */
		if (total > 0)
		{
			if (check_zeros(p, total))
				printf("✅ Memoria inicializada con ceros.\n");
			else
				printf("❌ ERROR: La memoria contiene basura.\n");
		}
		else
			printf("ℹ️  Tamaño 0: No se comprueba contenido pero el puntero existe.\n");
		
		/* 3. LIMPIEZA */
		free(p);
		printf("🗑️  Memoria liberada.\n");
	}
}

int	main(void)
{
	printf("\n=========================================");
	printf("\n       DEBUG FT_CALLOC - 42BARCELONA     ");
	printf("\n=========================================\n");

	test_calloc(10, sizeof(int), "Asignación estándar (10 ints)");
	test_calloc(1, sizeof(char), "Asignación mínima (1 char)");
	test_calloc(0, 10, "nmemb es 0 (Caso Puntero Único)");
	test_calloc(10, 0, "size es 0 (Caso Puntero Único)");
	test_calloc(0, 0, "Ambos son 0 (Caso Puntero Único)");
	
	/* TEST DE OVERFLOW (Opcional pero recomendado) */
	test_calloc(SIZE_MAX, 2, "Overflow de tamaño");

	printf("\n=========================================\n");
	return (0);
}
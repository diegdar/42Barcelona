/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: dichacon <dichacon@student.42barcelon      +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/07/05 17:21:44 by dichacon          #+#    #+#             */
/* Updated: 2026/07/08 12:55:00 by dichacon         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

/*
** MACRO DE PRUEBAS VERSÁTIL (TEST_PRINTF)
** Explota el uso de __VA_ARGS__ para aceptar cualquier número de argumentos.
** El "##" evita errores de compilación si no se le pasan argumentos extras.
** El truco de '" format "' concatena las comillas para envolver la salida de forma estética.
*/
#define TEST_PRINTF(format, ...) \
	do { \
		int res_ft = ft_printf("\t*ft_printf: " format "\n", ##__VA_ARGS__); \
		int res_orig = printf("\t*printf:    " format "\n", ##__VA_ARGS__); \
		printf("\t**Retornos -> ft: %d | orig: %d\n\n", res_ft, res_orig); \
	} while (0)

int	main(void)
{
	printf("==================================================\n");
	printf("          CSTR DE PRUEBAS PARA FT_PRINTF          \n");
	printf("==================================================\n\n");

	// 1. TESTS SIN PARÁMETROS (TEXTO PLANO)
	printf("--- CATEGORÍA: Texto Plano ---\n");
	TEST_PRINTF("Impresion limpia sin ningun tipo de dato");
	TEST_PRINTF("Texto con espacios y Simbolos! @#$^&*()");

	// 2. CHAR TESTS (%c)
	printf("--- CATEGORÍA: Caracteres (%%c) ---\n");
	TEST_PRINTF("Un char basico: '%c'", 'A');
	TEST_PRINTF("Un char de la tabla ASCII extendida: '%c'", 126);

	// 3. STRING TESTS (%s)
	printf("--- CATEGORÍA: Cadenas de texto (%%s) ---\n");
	TEST_PRINTF("Un string normal: '%s'", "hello 42");
	TEST_PRINTF("Un string vacio: '%s'", "");

	// 4. PRUEBAS CON VALOR HEXADECIMAL EN MINÚSCULA (%x)
	printf("--- CATEGORÍA: Hexadecimal Minuscula (%%x) ---\n");
	TEST_PRINTF("El numero cero en hex: '%x'", 0);
	TEST_PRINTF("El numero 255 (deberia ser ff): '%x'", 255);
	TEST_PRINTF("El numero maximo de un unsigned int: '%x'", UINT_MAX);
	TEST_PRINTF("Pasando un -1 a formato sin signo: '%x'", -1);

	// 5. PRUEBAS CON VALOR HEXADECIMAL EN MAYÚSCULA (%X)
	printf("--- CATEGORÍA: Hexadecimal Mayuscula (%%X) ---\n");
	TEST_PRINTF("El numero 255 (deberia ser FF): '%X'", 255);
	TEST_PRINTF("El numero maximo de un unsigned int: '%X'", UINT_MAX);
	TEST_PRINTF("Pasando un -1 a formato sin signo: '%X'", -1);

// 7. PRUEBAS CON EL SÍMBOLO DEL PORCENTAJE (%%)
	printf("--- CATEGORÍA: Símbolo de Porcentaje (%%%%) ---\n");
	TEST_PRINTF("Un porcentaje simple: %%");
	TEST_PRINTF("Tengo el 100%% de seguridad de que esto funciona");
	TEST_PRINTF("Seis porcentajes seguidos: %%%%%%");

	return (0);
}

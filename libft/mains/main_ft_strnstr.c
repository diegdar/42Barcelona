#include "libft.h"
#include <stdio.h>

// Función para imprimir los resultados individuales
void f_print_result(char *big, char *little, char *result, size_t n)
{
    printf("**valor de big: %.*s\n", (int)n, big);
    printf("**valor de little: %s\n", little);
    printf("**valor de n: %zu\n", n);

    if (result)
    {
        printf("El valor de result es: %s\n\n", result);
    }
    else
    {
        printf("El valor de 'result' es: NULL\n\n");
    }
}

// Nueva función auxiliar para encapsular cada caso de prueba
void test_strnstr(char *big, char *little, size_t n, char *msg)
{
    char *result;

    printf("\n>>%s\n", msg);
    result = ft_strnstr(big, little, n);
    f_print_result(big, little, result, n);
}

int main(void)
{
    char    *big;
    size_t  big_len;

    big = "Foo Bar Baz";
    big_len = ft_strlen(big);

    // Caso 1: Encontrar al principio
    test_strnstr(big, "Foo", big_len, 
        "Se DEBERIA Encontrar little en la primera posicion de big, buscando en todos los bytes de big");

    // Caso 2: No coinciden todos los caracteres
    test_strnstr(big, "For", big_len, 
        "NO Se DEBERIA Encontrar little(retornara NULL) porque no coinciden todos los caracteres de busqueda");

    // Caso 3: Encontrar más adelante
    test_strnstr(big, "Bar", big_len, 
        "Se DEBERIA Encontrar little pero NO en las primeras posiciones de big, buscando en todos los bytes de big");

    // Caso 4: Límite de 'n' insuficiente
    test_strnstr(big, "Bar", 4, 
        "No se DEBERIA Encontrar little(retornara NULL) a pesar de encontrarse en big porque en los primeros caracteres de 'n' no se encuentra");

    // Caso 5: No existe en el string
    test_strnstr(big, "no_found", big_len, 
        "Si no se encuentra little en big se DEBERIA devolver NULL,Buscando en todos los bytes de big");

    // Caso 6: Little vacío
    test_strnstr(big, "", big_len, 
        "Si little es un string vacio, se DEBERIA devolver big entero(todos sus caracteres)");

    // Caso 7: Len negativo (size_t max)
    test_strnstr("aaabcabcd", "aabc", -1, 
        "Que pasa si le pasamos len negativo?");

    return (0);
}

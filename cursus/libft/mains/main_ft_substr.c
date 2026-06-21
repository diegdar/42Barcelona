#include "libft.h"
#include <stdio.h>

static void    test_fn(char const *src, unsigned int start, size_t len, char *test_name)
{
    char    *sub;

    printf("\n--- Test: %s --- ", test_name);
    printf("\nValor de src: %s", src);
    printf("\nValor de start: %d", start);
    printf("\nValor de len: %zu", len);
    sub = ft_substr(src, start, len);
    if (!sub)
    {
        printf("\nLa subcadena devuelve un valor NULL");
        return ;     
    }
    printf("\n>>Valor de ft_substr():%s\n", sub);

}

int main(void)
{
    char            *src;
    unsigned int    start;
    size_t          len;
    
    src = "Hola paco";

    start = 0;
    len = 9;
    test_fn(src, start, len, "La subcadena se toma desde el incio de src hasta el final de src");

    
    start = 5;
    len = 4;
    test_fn(src, start, len, "La subcadena comienza en el caracter 5('p' de 'paco') hasta el final de src");

    start = 0;
    len = 10;
    test_fn(src, start, len, "Que pasa si pedimos que 'len' sea mayor al limite de src?");

    start = 9;
    len = 2;
    test_fn(src, start, len, "Que pasa si start esta fuera del limite de src?");

    return (0);
}

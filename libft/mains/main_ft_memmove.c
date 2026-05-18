#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	//Caso 1: sin solapamiento
	char	data1[20] = "123456789";
	char	data2[20] = "123456789";

	printf("---Caso: sin solapamiento --- \n");
	memmove(data1 + 11, data1, 5);
	ft_memmove(data2 + 11, data2, 5);
	printf("Mía: %s | Original: %s\n", data1, data2);

	//Caso 2: Solapamiento dest > src: hacia atras
	char	data3[20] = "123456789";
	char	data4[20] = "123456789";

	printf("---Caso: dest > src --- \n");
	memmove(data3 + 2, data3, 5);
	ft_memmove(data4 + 2, data4, 5);
	printf("Mía: %s | Original: %s\n", data3, data4);

	//Caso 3: Solapamiento dest < src: hacia atras
	char	data5[20] = "123456789";
	char	data6[20] = "123456789";

	printf("---Caso: dest < src --- \n");
	memmove(data5, data5 + 2, 5);
	ft_memmove(data6, data6 + 2, 5);
	printf("Mía: %s | Original: %s\n", data5, data6);

	//Caso 4: n == 0
	char	data7[20] = "123456789";
	char	data8[20] = "123456789";

	printf("---Caso: n == 0 --- \n");
	memmove(data7, data7 + 2, 0);
	ft_memmove(data8, data8 + 2, 0);
	printf("Mía: %s | Original: %s\n", data7, data8); // no deberia mover nada


	//Caso 5: dest == src
	char	data9[20] = "123456789";
	char	*data10 = data9;

	printf("---Caso: dest == src --- \n");
	memmove(data9, data9, 5);
	ft_memmove(data10, data10, 5);
	printf("Mía: %s | Original: %s\n", data9, data10); // no deberia mover nada

	//Caso 6: dest && src == NULL
	char	*data11 = NULL;
	char	*data12 = NULL;

	printf("---Caso: dest && src == NULL --- \n");
	memmove(data11, data11, 5);
	ft_memmove(data12, data12, 5);
	printf("Mía: %p | Original: %p\n", data11, data12); // Comprobar qué pasa cuando ambos son NULL (no debería crashear).
	return (0);
}

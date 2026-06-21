#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("\nNumero de nodos; %d", ft_lstsize(NULL));

	free(node1);
	free(node2);
	free(node3);
	return (0);
}

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*last;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	if (!node1 || !node2 || !node3)
	{
		printf("No se pudo asignar memoria\n");
		free(node1);
		free(node2);
		free(node3);
		return (1);
	}
	node1->content = "first_node";
	node1->next = node2;
	node2->content = "node2";
	node2->next = node3;
	node3->content = "last_node";
	node3->next = NULL;
	last = ft_lstlast(node1);
	if (last)
		printf("\n**Valor devuelto por ft_lstlast(): %s\n",
			(char *)last->content);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}

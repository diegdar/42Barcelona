#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*current;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	if (!node1 || !node2 || !node3)
	{
		printf("\nNo se ha podido asignar memoria en alguno nodo");
		free(node1);
		free(node2);
		free(node3);
		return (1);
	}

	head = node1;
	node1->content = "node1";
	node2->content = "node2";
	node3->content = "new_node";
	node1->next = node2;
	node2->next = NULL;
	node3->next = NULL;

	ft_lstadd_back(&head, node3);

	current = head;
	while (current->next != NULL)
		current = current->next;

	printf("\n**El ultimo node es: %s", (char *)current->content);

	free(node1);
	free(node2);
	free(node3);
	return (0);
}

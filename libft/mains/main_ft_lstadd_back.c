#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*new;
	t_list	*current;
	int	*num_1;
	int	*num_2;

	head = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	num_1 = malloc(sizeof(int));
	num_2 = malloc(sizeof(int));

	*num_1 = 10;
	*num_2 = 20;

	head->content = num_1;
	new->content = num_2;
	ft_lstadd_back(&head, new);
	current = head;
	while (current != NULL)
	{
		printf("Nodo: %d\n",*(int *)current->content);
		current = current->next;
	}

	free(head);
	free(new);
	free(num_1);
	free(num_2);
	return (0);
}

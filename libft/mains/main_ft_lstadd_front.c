#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*new_node;
	t_list	*current;

	head = malloc(sizeof(t_list));
	new_node = malloc(sizeof(t_list));
	if (!head || !new_node)
		return (1);

	head->content = "old_node";
	head->next = NULL;
	new_node->content = "new_node";
	new_node->next = NULL;

	ft_lstadd_front(&head, new_node);

	current = head;
	while (current != NULL)
	{
		printf("Content: %s\n", (char *)current->content);
		current = current->next;
	}

	current = head->next;
	free(head);
	free(current);
	return (0);
}

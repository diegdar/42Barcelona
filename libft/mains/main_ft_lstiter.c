#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_player
{
	char	*name;
} t_player;

void	print_player(void	*content)
{
	t_player	*player;
	player = (t_player *)content;
	printf("\nNombre jugador: %s", player->name);
}

void	del_player(void *ptr)
{
	t_player	*player;

	player = ptr;
	free(player);
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_player	*player1;
	t_player	*player2;

	player1 = malloc(sizeof(t_player));
	if (!player1)
		return (1);
	player1->name = "Luis Diaz";

	node1 = ft_lstnew(player1);
	if (!node1)
	{
		free(player1);
		return (1);
	}

	player2 = malloc(sizeof(t_player));
	if (!player2)
	{
		ft_lstdelone(node1, del_player);
		return (1);
	}
	player2->name = "Guillermo Gomez";
	node2 = ft_lstnew(player2);
	if (!node2)
	{
		ft_lstdelone(node1, del_player);
		free(player2);
		return (1);
	}

	head = node1;
	node1->next = node2;

	ft_lstiter(head, print_player);

	ft_lstclear(&head, del_player);
	return (0);
}

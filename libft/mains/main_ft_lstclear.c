#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_player
{
	char	*name;
	char	*team;
} t_player;

void	del_player(void *ptr)
{
	t_player	*player;

	player = ptr;
	free(player->name);
	free(player->team);
	free(player);
}

int	main(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_player	*player1;
	t_player	*player2;

	lst = NULL;

	player1 = malloc(sizeof(t_player));
	if	(!player1)
	{
		printf("\nNo se pudo asignar memoria con malloc");
		return (1);
	}

	player1->name = malloc(20);
	player1->team = malloc(15);
	if (!player1->name || !player1->team)
	{
		printf("\nNo se pudo asignar memoria con malloc");
		del_player(player1);
		return (1);
	}

	player2 = malloc(sizeof(t_player));
	if	(!player2)
	{
		printf("\nNo se pudo asignar memoria con malloc");
		del_player(player1);
		return (1);
	}

	player2->name = malloc(20);
	player2->team = malloc(15);
	if (!player2->name || !player2->team)
	{
		printf("\nNo se pudo asignar memoria con malloc");
		del_player(player1);
		del_player(player2);
		return (1);
	}

	node1 = ft_lstnew(player1);
	node2 = ft_lstnew(player2);
	if	(!node1 || !node2)
	{
		printf("\nNo se pudo asignar memoria con malloc");
		free(node1);
		free(node2);
		del_player(player1);
		del_player(player2);
		return (1);
	}

	node1->next = node2;
	lst = node1;

	ft_lstclear(&lst, del_player);

	if (lst == NULL)
		printf("\n✅  La lista esta vacia");
	else
		printf("\n❌ La lista no se vacio correctamente!.");
}

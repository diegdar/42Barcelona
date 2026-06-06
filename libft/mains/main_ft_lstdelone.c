#include "libft.h"
#include <stdlib.h>

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
	t_list		*node;
	t_player	*player;

	node = malloc(sizeof(t_list));
	player = malloc(sizeof(t_player));

	if (!node || !player)
	{
		free(node);
		free(player);
		return (1);
	}

	player->name = malloc(20);
	player->team = malloc(15);

	if (!player->name || !player->team)
	{
		free(player->name);
		free(player->team);
		free(player);
		free(node);
		return (1);
	}

	node->content = player;

	ft_lstdelone(node, del_player);

	return (0);
}
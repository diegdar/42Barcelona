#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*duplicate_content(void *content)
{
	char	*str;

	str = (char *)content;
	return (ft_strdup(str));
}

void	del_content(void *content)
{
	free(content);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*newlst;

	lst = NULL;

	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("uno")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("dos")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("tres")));

	printf("LISTA ORIGINAL:\n");
	print_list(lst);

	newlst = ft_lstmap(lst, duplicate_content, del_content);

	printf("\nLISTA MAPEADA:\n");
	print_list(newlst);

	ft_lstclear(&lst, del_content);
	ft_lstclear(&newlst, del_content);

	return (0);
}

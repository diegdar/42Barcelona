/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dichacon <dichacon@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:36:39 by dichacon          #+#    #+#             */
/*   Updated: 2026/06/03 19:03:42 by dichacon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;

	if (!lst)
		return (0);
	current = lst;
	count = 0;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

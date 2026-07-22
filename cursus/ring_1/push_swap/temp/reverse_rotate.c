#include "../push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{

}

void	ft_rra(t_stack **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
#include "../push_swap.h"

void	ft_rotate(t_stack **stack)
{

}

void	ft_ra(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
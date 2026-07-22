#include "../push_swap.h"

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	tmp = *src;
	*src = *dst;
	*dst = tmp;
}

void	ft_pa(t_stack **a, t_stack **b, t_counter *counter)
{
	if (!is_op_validate(a, counter))
		return ;
	if (!is_op_validate(b, counter))
		return ;	
	ft_push(b, a);
	write(1, "sa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, t_counter *counter)
{
	if (!is_op_validate(a, counter))
		return ;
	if (!is_op_validate(b, counter))
		return ;
	ft_push(a, b);
	write(1, "sb\n", 3);
}
#include <push_swap.h>
#include <stdio.h>

t_uint	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	get_chunk_size(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = 0;
	if (stack_a != NULL)
		size += ft_lstsize(*stack_a);
	if (stack_b != NULL)
		size += ft_lstsize(*stack_b);
	if (size >= 250)
		return (500 / 8);
	return (size / 5);
}

void	restore_chamber(long *high, long *small, int *min, int chk_sz)
{
	*high = *high - 1;
	if (*small <= -1)
	{
		*small = *high - (chk_sz * 0.25);
		if (*high > (*min - 1))
			*high = *min - 1;
	}
}

void	empty_chamber(long *small, int *chamber, t_list **stack_a)
{
	int	c;

	c = *chamber;
	if (*small <= -1)
	{
		while (c != 0)
		{
			rrx('a', stack_a, 1);
			c--;
		}
		*chamber = 0;
	}
}

long	triadic(int cond, long true_v, long false_v)
{
	if (cond)
		return (true_v);
	return (false_v);
}

void	push_smallest(t_list **a, t_list **b, long *small, long high)
{
	push_to_a(a, b, *small);
	rx('a', a, 1);
	*small = triadic(*small + 1 > high, *small, *small + 1);
}

int	variable_setters(t_list *b, long *high, long *small, t_uint chk_sz)
{
	*high = ft_lstsize(b) - 1;
	*small = *high - chk_sz;
	return (*small);
}
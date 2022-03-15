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

void	push_to_a(t_list **a, t_list **b, long number)
{
	if (find_number(*b, number) == 0 && b != NULL & (*b)->value != number)
		return ;
	smart_rotate(b, number, 'b', 0);
	px('a', b, a, 1);
}

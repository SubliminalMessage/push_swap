#include <push_swap.h>

// Rotates the stack in the most efficient direction, so 'find' is on top
void    smart_rotate(t_list **root, unsigned int find, char stack)
{
	int	len;
    int	steps;

	len = ft_lstsize(*root);
	steps = find_number(*root, find, len);
	if (steps == 0)
		return ;
	if (len == 3)
	{
		if ((*root)->value == (find + 2) && (*root)->next->value == (find + 1))
		{
			sx(stack, root, 1);
			rrx('a', root, 1);
		}
		else if ((*root)->value == (find + 1) && (*root)->next->value == find)
			sx(stack, root, 1);
		else
			rx(stack, root, 1);
		return ;
	}
	else
		rotate_n_times(root, steps, stack);
}

int     find_number(t_list *stack, unsigned int find, int len)
{
	int	index;
	
	index = 0;
	while (stack != NULL && stack->value != find)
	{
		index++;
		stack = stack->next;
	}
	if ((len - index) < index)
		return ((len - index) * -1);
	return (index);
}

void	rotate_n_times(t_list **root, int steps, char stack)
{
	int	is_negative;

	is_negative = 0;
	if (steps < 0)
	{
		is_negative = 1;
		steps *= -1;
	}
	while (steps != 0)
	{
		if (is_negative)
			rrx(stack, root, 1);
		else
			rx(stack, root, 1);
		steps--;
	}
}

void	empty_stack(t_list **src, t_list **dst, char drop_at)
{
	int	len;

	len = ft_lstsize(*src);
	while (len != 0)
	{
		px(drop_at, src, dst, 1);
		len--;
	}
}
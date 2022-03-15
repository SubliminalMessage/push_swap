/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:16:51 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/15 19:16:39 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// Rotates the stack in the most efficient direction, so 'find' is on top
void	smart_rotate(t_list **root, unsigned int find, char stack, int effic)
{
	int	len;
	int	steps;

	len = ft_lstsize(*root);
	steps = find_number(*root, find);
	if (steps == 1 && effic)
	{
		if ((*root)->value == (find + 2))
			rx(stack, root, 1);
		else
			sx(stack, root, 1);
	}
	else if (len == 3 && effic)
	{
		if ((*root)->value == (find + 2) && (*root)->next->value == (find + 1))
		{
			sx(stack, root, 1);
			rrx(stack, root, 1);
		}
		else if ((*root)->value == (find + 1) && (*root)->next->value == find)
			sx(stack, root, 1);
		return ;
	}
	rotate_n_times(root, steps, stack);
}

int	find_number(t_list *stack, unsigned int find)
{
	int	index;
	int	len;

	len = ft_lstsize(stack);
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

	if (steps == 0)
		return ;
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

void	empty_stack(t_list **src, t_list **dst, char drop_at, int drop_count)
{
	int	len;

	len = 0;
	while (len < drop_count)
	{
		px(drop_at, src, dst, 1);
		len++;
	}
}

unsigned int	*to_array(t_list *stack)
{
	unsigned int	*array;
	int				i;

	i = 0;
	array = malloc(sizeof(unsigned int) * ft_lstsize(stack));
	while (stack != NULL)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

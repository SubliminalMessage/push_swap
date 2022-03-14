/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:20:34 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/14 15:24:41 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	sort_and_empty_stack(t_list **stack_a, t_list **stack_b)
{
	unsigned int	stack;
	unsigned int	value;
	int				size;
	int				found;
	int				chunk_size;

	size = ft_lstsize(*stack_a);
	if (size >= 250)
		chunk_size = 500 / 8;
	else
		chunk_size = size / 5;
	stack = 0;
	found = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->value < ((stack + 1) * chunk_size))
		{
			value = (*stack_a)->value;
			px('b', stack_a, stack_b, 1);
			found++;
			if (found >= chunk_size)
			{
				found = 0;
				stack++;
			}
			if (value >= (stack * chunk_size) + (chunk_size / 2))
			{
				if ((*stack_a) != NULL && (*stack_a)->value > ((stack + 1) * chunk_size))
					rr(stack_a, stack_b, 1);
				else
					rx('b', stack_b, 1);
			}
		}
		else
			rx('a', stack_a, 1);
	}
	int			chamber = 0;
	long int	highest = ft_lstsize(*stack_b) - 1;
	long int	smallest = highest - chunk_size;
	int			min_chamber = smallest;
	while (*stack_b != NULL)
	{
		int	high_len = find_number(*stack_b, (unsigned int) highest);
		int	small_len = find_number(*stack_b, (unsigned int) smallest);

		if (smallest >= 0 && ft_abs(high_len) > ft_abs(small_len))
		{
			if (smallest < min_chamber)
				min_chamber = smallest;
			smart_rotate(stack_b, smallest, 'b', 0);
			px('a', stack_b, stack_a, 1);
			rx('a', stack_a, 1);
			chamber++;
			smallest++;
		}
		else
		{
			smart_rotate(stack_b, highest, 'b', 0);
			px('a', stack_b, stack_a, 1);
			if (smallest <= -1)
			{
				while (chamber != 0)
				{
					rrx('a', stack_a, 1);
					chamber--;
				}
			}
			highest--;
			if (smallest <= -1)
			{
				smallest = highest - (chunk_size * 0.25);
				if (highest > (min_chamber - 1))
					highest = min_chamber - 1;
			}
		}
		if (smallest >= highest)
				smallest = -1;
	}
	smart_rotate(stack_a, 0, 'a', 0);
}


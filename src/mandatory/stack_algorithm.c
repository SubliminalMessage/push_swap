/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:20:34 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/15 19:09:27 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

static void	push_b_while(t_list **st_a, t_list **st_b, t_uint *found, t_uint *stack)
{
	t_uint	chk_sz;

	chk_sz = get_chunk_size(st_a, st_b);
	if ((*st_a)->value < ((*stack + 1) * chk_sz))
	{
		px('b', st_a, st_b, 1);
		*found = *found + 1;
		if (*found >= chk_sz)
		{
			*found = 0;
			*stack = *stack + 1;
		}
		if ((*st_b)->value >= (*stack * chk_sz) + (chk_sz / 2))
		{
			if ((*st_a) != NULL && (*st_a)->value > ((*stack + 1) * chk_sz))
				rr(st_a, st_b, 1);
			else
				rx('b', st_b, 1);
		}
	}
	else
		rx('a', st_a, 1);
}

void	push_to_a(t_list **a, t_list **b, long number)
{
	if (find_number(*b, number) == 0 && b != NULL & (*b)->value != number)
		return ;
	smart_rotate(b, number, 'b', 0);
	px('a', b, a, 1);
}

static void	push_back(t_list **st_a, t_list **st_b, int chk_sz, int chamber)
{
	long int	highest;
	long int	smallest;
	int			min_chamb;
	int			high_len;
	int			small_len;

	min_chamb = variable_setters(*st_b, &highest, &smallest, chk_sz);
	while (*st_b != NULL)
	{
		high_len = find_number(*st_b, (unsigned int) highest);
		small_len = find_number(*st_b, (unsigned int) smallest);
		if (smallest >= 0 && ft_abs(high_len) > ft_abs(small_len))
		{
			min_chamb = triadic(smallest < min_chamb, smallest, min_chamb);
			push_smallest(st_a, st_b, &smallest, highest);
			chamber++;
		}
		else
		{
			push_to_a(st_a, st_b, highest);
			empty_chamber(&smallest, &chamber, st_a);
			restore_chamber(&highest, &smallest, &min_chamb, chk_sz);
		}
		smallest = triadic(smallest > highest, -1, smallest);
	}
}



void	sort_and_empty_stack(t_list **st_a, t_list **st_b)
{
	t_uint	stack;
	t_uint	found;
	t_uint	chk_sz;

	// Push everything to B
	chk_sz = get_chunk_size(st_a, st_b);
	stack = 0;
	found = 0;
	while (*st_a != NULL)
		push_b_while(st_a, st_b, &found, &stack);

	// Push everything back to A
	push_back(st_a, st_b, chk_sz, 0);

	// Make '0' be the first position
	smart_rotate(st_a, 0, 'a', 0);
}


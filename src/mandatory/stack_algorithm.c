/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:20:34 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/15 19:14:33 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_back(t_list **st_a, t_list **st_b, int chk_sz, int chamber);
static void	push_b_while(t_list **a, t_list **b, t_uint *fnd, t_uint *stk);

void	sort_and_empty_stack(t_list **st_a, t_list **st_b)
{
	t_uint	stack;
	t_uint	found;
	t_uint	chk_sz;

	chk_sz = get_chunk_size(st_a, st_b);
	stack = 0;
	found = 0;
	while (*st_a != NULL)
		push_b_while(st_a, st_b, &found, &stack);
	push_back(st_a, st_b, chk_sz, 0);
	smart_rotate(st_a, 0, 'a', 0);
}

static void	push_b_while(t_list **a, t_list **b, t_uint *fnd, t_uint *stk)
{
	t_uint	chk_sz;

	chk_sz = get_chunk_size(a, b);
	if ((*a)->value < ((*stk + 1) * chk_sz))
	{
		px('b', a, b, 1);
		*fnd = *fnd + 1;
		if (*fnd >= chk_sz)
		{
			*fnd = 0;
			*stk = *stk + 1;
		}
		if ((*b)->value >= (*stk * chk_sz) + (chk_sz / 2))
		{
			if ((*a) != NULL && (*a)->value > ((*stk + 1) * chk_sz))
				rr(a, b, 1);
			else
				rx('b', b, 1);
		}
	}
	else
		rx('a', a, 1);
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

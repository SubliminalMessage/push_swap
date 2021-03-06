/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algo_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:11:37 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/16 15:11:39 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

long	triadic(int cond, long true_v, long false_v)
{
	if (cond)
		return (true_v);
	return (false_v);
}

int	variable_setters(t_list *b, long *high, long *small, t_uint chk_sz)
{
	*high = ft_lstsize(b) - 1;
	*small = *high - chk_sz;
	return (*small);
}

void	push_smallest(t_list **a, t_list **b, long *small, long high)
{
	push_to_a(a, b, *small);
	rx('a', a, 1);
	*small = triadic(*small + 1 > high, *small, *small + 1);
}

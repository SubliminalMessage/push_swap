/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chamber_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:30:26 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/14 15:32:45 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
    Chamber Sort Algorithm

    1. Check if the stack A is sorted
        -> If it's sorted go to #6
        -> If it's not sorted, go to #2
    2. Bring the smallest number to the top of the stack
    3. Check if stack A is sorted (again)
        - If it's sorted, go to #6
        -> If it's not sorted, go to #4
    4. Push to B
    5. Go back to #1
    6. Push every number from Stack B to Stack A, until B is empty
    7. You're done
*/

void	chamber_sort(t_list **stack_a, t_list **stack_b)
{
	int	smallest;
	int	pushed;

	smallest = 0;
	pushed = 0;
	while (!is_sorted(*stack_a))
	{
		smart_rotate(stack_a, smallest, 'a', 1);
		if (is_sorted(*stack_a))
			break ;
		px('b', stack_a, stack_b, 1);
		pushed++;
		smallest++;
	}
	empty_stack(stack_b, stack_a, 'a', pushed);
}

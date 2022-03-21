/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <dangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:26:34 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/21 17:47:54 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// https://numbergenerator.org/randomnumbergenerator
//ARG=`perl -e "use List::Util 'shuffle'; print join(' ', shuffle(0..(5 - 1)))"`
int	main(int argc, char **argv)
{
	t_list	*sorted;
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	sorted = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		parse_numbers(argc, argv, &sorted, &stack_a);
		merge_sort(&sorted);
		transfer_numbers(&sorted, &stack_a);
		size = ft_lstsize(sorted);
		if (size >= 50)
			sort_and_empty_stack(&stack_a, &stack_b);
		else
			chamber_sort(&stack_a, &stack_b);
		clean_exit(&sorted, &stack_a, &stack_b, NULL);
	}
}

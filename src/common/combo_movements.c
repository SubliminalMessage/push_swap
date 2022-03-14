/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:13:35 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/14 15:14:26 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	ss(t_list **stack_a, t_list **stack_b, int print_text)
{
	sx('a', stack_a, 0);
	sx('b', stack_b, 0);
	if (print_text)
		write(1, "ss\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int print_text)
{
	rx('a', stack_a, 0);
	rx('b', stack_b, 0);
	if (print_text)
		write(1, "rr\n", 3);
}

void	rrr(t_list **stack_a, t_list **stack_b, int print_text)
{
	rrx('a', stack_a, 0);
	rrx('b', stack_b, 0);
	if (print_text)
		write(1, "rrr\n", 4);
}

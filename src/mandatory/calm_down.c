/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calm_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:29:50 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/14 15:30:18 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	transfer_numbers(t_list **sorted, t_list **stack)
{
	t_list	*sort_node;
	int		i;

	sort_node = *sorted;
	i = 0;
	while (sort_node != NULL)
	{
		calm_number_down(stack, sort_node->original, i);
		sort_node->value = i;
		i++;
		sort_node = sort_node->next;
	}
}

void	calm_number_down(t_list **root, int original, int value)
{
	t_list	*node;

	if (root == NULL)
		return ;
	node = *root;
	while (node != NULL)
	{
		if (node->original == original)
		{
			node->value = value;
			return ;
		}
		node = node->next;
	}
}

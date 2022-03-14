/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:15:28 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/14 15:15:32 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

int	is_sorted(t_list *root)
{
	int	previous;

	if (root == NULL)
		return (1);
	previous = root->original;
	while (root->next != NULL)
	{
		root = root->next;
		if (previous > root->original)
			return (0);
		previous = root->original;
	}
	return (1);
}

int	are_duplicates(t_list *root)
{
	int		current;
	t_list	*node;

	while (root != NULL)
	{
		current = root->original;
		node = root->next;
		while (node != NULL)
		{
			if (current == node->original)
				return (1);
			node = node->next;
		}
		root = root->next;
	}
	return (0);
}

void	clean_exit(t_list **a, t_list **b, t_list **c, char *msg)
{
	ft_lstclear(a);
	ft_lstclear(b);
	ft_lstclear(c);
	if (msg != NULL)
		ft_putstr_fd(msg, 2);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:24:56 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/14 15:24:57 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_list	*sort_and_merge(t_list *a, t_list *b);
static void		split_list(t_list *src, t_list **front, t_list **back);

void	merge_sort(t_list **root)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *root;
	if ((head == NULL) || (head->next == NULL))
		return ;
	split_list(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*root = sort_and_merge(a, b);
}

static t_list	*sort_and_merge(t_list *a, t_list *b)
{
	t_list	*result;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	result = NULL;
	if (a->original <= b->original)
	{
		result = a;
		result->next = sort_and_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sort_and_merge(a, b->next);
	}
	return (result);
}

static void	split_list(t_list *src, t_list **front, t_list **back)
{
	t_list	*fast;
	t_list	*slow;

	slow = src;
	fast = src->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = src;
	*back = slow->next;
	slow->next = NULL;
}

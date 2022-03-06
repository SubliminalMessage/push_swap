/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:43:23 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/06 18:46:06 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstclear(t_list **lst)
{
	t_list	*next_elem;
	t_list	*temp;

	if (lst == NULL)
		return ;
	next_elem = *lst;
	while (next_elem != NULL)
	{
		temp = next_elem;
		next_elem = next_elem->next;
		free(temp);
	}
	*lst = NULL;
}

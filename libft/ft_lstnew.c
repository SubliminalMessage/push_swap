/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:43:12 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/06 16:49:58 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(int original)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (new_element != NULL)
	{
		new_element->original = original;
		new_element->next = NULL;
	}
	return (new_element);
}

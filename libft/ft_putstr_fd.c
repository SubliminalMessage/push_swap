/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:48:11 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/06 00:25:36 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (s)
	{
		index = 0;
		while (*(s + index))
		{
			ft_putchar_fd(*(s + index), fd);
			index++;
		}
	}
}

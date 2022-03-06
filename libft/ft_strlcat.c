/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:38:07 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/06 00:26:05 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	index;

	dst_length = ft_strlen(dst);
	if (dst_length >= dstsize)
		return (dstsize + ft_strlen(src));
	index = 0;
	while (*(src + index) && (dst_length + index) < (dstsize - 1))
	{
		*(dst + dst_length + index) = *(src + index);
		index++;
	}
	*(dst + dst_length + index) = '\0';
	return (dst_length + ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:14:58 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/06 00:25:56 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	int		str_len;
	char	*str_pointer;

	str_len = ft_strlen(s1);
	str_pointer = malloc(sizeof(char) * (str_len + 1));
	if (str_pointer != NULL)
		ft_strlcpy(str_pointer, s1, (str_len + 1));
	return (str_pointer);
}

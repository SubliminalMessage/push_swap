/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutch <dutch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:02:57 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/15 19:22:27 by dutch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_isspace(char c);
static long int	return_final_value(long long final, int negative_sign);

long int	ft_atoi(const char *str)
{
	long long	final;
	int			negative_sign;
	int			index;

	index = 0;
	final = 0;
	negative_sign = 1;
	while (ft_isspace(*(str + index)))
		index++;
	if (*(str + index) == '-' || *(str + index) == '+')
	{
		if (*(str + index) == '-')
			negative_sign = -1;
		index++;
	}
	while (*(str + index))
	{
		if (!ft_isdigit(*(str + index)))
			break ;
		final = (final * 10) + (*(str + index) - 48);
		index++;
	}
	return (return_final_value(final, negative_sign));
}

static long int	return_final_value(long long final, int negative_sign)
{
	if (final > 9223372036854775807 && negative_sign < 0)
		return (0);
	else if (final > 9223372036854775807 && negative_sign > 0)
		return (-1);
	return ((long)(final * negative_sign));
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

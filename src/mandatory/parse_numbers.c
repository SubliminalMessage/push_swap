/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <dangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:25:06 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/14 15:26:03 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	parse_numbers(int argc, char **argv, t_list **sort, t_list **stack)
{
	int			i;
	int			j;
	char		**num_arr;
	long int	number;

	i = 0;
	while (++i < argc)
	{
		num_arr = ft_split(argv[i], ' ');
		j = -1;
		while (num_arr[++j] != NULL)
		{
			number = ft_atoi(num_arr[j]);
			if (ft_isalpha(num_arr[j]))
				clean_exit(sort, stack, NULL, "Error\n");
			if (number > 2147483647 || number < -2147483648)
				clean_exit(sort, stack, NULL, "Error\n");
			ft_lstadd_back(sort, ft_lstnew(number));
			ft_lstadd_back(stack, ft_lstnew(number));
			free(num_arr[j]);
		}
		free(num_arr);
	}
	if (is_sorted(*sort) || are_duplicates(*sort) || ft_lstsize(*sort) == 1)
		clean_exit(sort, stack, NULL, "Error\n");
}

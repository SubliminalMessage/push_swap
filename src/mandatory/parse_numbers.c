/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <dangonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:25:06 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/21 16:44:31 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	parse_numbers(int argc, char **argv, t_list **sort, t_list **stack)
{
	int			i;
	int			j;
	char		**n_arr;
	long int	num;

	i = 0;
	while (++i < argc)
	{
		n_arr = ft_split(argv[i], ' ');
		j = -1;
		while (n_arr[++j] != NULL)
		{
			num = ft_atoi(n_arr[j]);
			if (ft_isalpha(n_arr[j]) || num > 2147483647 || num < -2147483648)
				clean_exit(sort, stack, NULL, "Error\n");
			ft_lstadd_back(sort, ft_lstnew(num));
			ft_lstadd_back(stack, ft_lstnew(num));
			free(n_arr[j]);
		}
		free(n_arr);
	}
	if (is_sorted(*sort))
		clean_exit(sort, stack, NULL, "");
	if (are_duplicates(*sort) || ft_lstsize(*sort) == 1)
		clean_exit(sort, stack, NULL, "Error\n");
}

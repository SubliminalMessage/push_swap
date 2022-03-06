#include <push_swap.h>

#include <stdio.h> // <??

void	clean_exit(t_list **a, t_list **b, t_list **c, char *msg)
{
	ft_lstclear(a);
	ft_lstclear(b);
	ft_lstclear(c);
	if (msg != NULL)
		ft_putstr_fd(msg, 1);
	exit(0);
}

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

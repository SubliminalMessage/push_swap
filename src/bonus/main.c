#include <checker.h>

#include <stdio.h>

int main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;
    char    *operation;
    int     op_count;
	//int		everything_ok;

    stack_a = NULL;
    stack_b = NULL;
    op_count = 0;
    if (argc > 1)
    {
        parse_input(argc, argv, &stack_a);
        operation = get_next_line(1);
        while (operation != NULL)
        {
            execute_operation(operation, &stack_a, &stack_b);
			free(operation);
            operation = get_next_line(1);
        }
		if (is_sorted(stack_a) && stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
    }
}

void    parse_input(int argc, char **argv, t_list **stack)
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
				clean_exit(stack, NULL, NULL, "Error\n");
			if (number > 2147483647 || number < -2147483648)
				clean_exit(stack, NULL, NULL, "Error\n");
			ft_lstadd_back(stack, ft_lstnew(number));
			free(num_arr[j]);
		}
		free(num_arr);
	}
	if (is_sorted(*stack) || are_duplicates(*stack) || ft_lstsize(*stack) == 1)
		clean_exit(stack, NULL, NULL, "Error\n");
}

void	execute_operation(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sx('a', stack_a, 0);
	else if (!ft_strncmp(op, "sb\n", 3))
		sx('b', stack_b, 0);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "pa\n", 3))
		px('a', stack_b, stack_a, 0);
	else if (!ft_strncmp(op, "pb\n", 3))
		px('b', stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "ra\n", 3))
		rx('a', stack_a, 0);
	else if (!ft_strncmp(op, "rb\n", 3))
		rx('b', stack_b, 0);
	else if (!ft_strncmp(op, "rra\n", 4))
		rrx('a', stack_a, 0);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrx('b', stack_b, 0);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(op, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else
		clean_exit(stack_a, stack_b, NULL, "Error\n");
}
#include <push_swap.h>

//int find_number_range(t_list **stack_a, t_list **stack_b);
/*
int    can_insert_number(t_list **stack_a, t_list **stack_b)
{
    unsigned int *array_a;
    unsigned int *array_b;
    int size_a;
    int size_b;

    array_a = to_array(*stack_a);
    size_a = ft_lstsize(*stack_a);
    array_b = to_array(*stack_b);
    size_b = ft_lstsize(*stack_b);

    /////////
    if (!size_a)
            return (0);
        if (size_b < 2)
            return (1);
        else if (array_a[0] > array_b[0])
        {
            if (array_a[0] < array_b[size_b - 1] && array_b[0] < array_b[size_b - 1])
                return (1);
            else if (array_a[0] > array_b[size_b - 1] && array_b[0] > array_b[size_b - 1])
                return (1);
        }
        else if (array_a[0] < array_b[size_b - 1] && array_b[size_b - 1] < array_b[0])
            return (1);
	return (0);
    /////////

    free(array_a);
    free(array_b);
}

int    get_number_position(unsigned int num, t_list *stack)
{
    int		i;
    unsigned int *array;
    int size;

	i = 0;
    size = ft_lstsize(stack);
    array = to_array(stack);
	if (num > array[0] && num < array[size - 1]) // if it's already there
		return (i);
	while (i < size && num > array[i]) // search the start of the list (the lowest number)
		i++;
	if (i != size) // if there is still room to look forward
	{
		while (i < size - 1 && num < array[i]) // Look for the next max number
			i++;
		if (i == size - 1 && array[i] > num) // If you didn't found it, it means you're the new max
			i = size;
	}
	if (i == size) // Shit didn't work, lets try another thing
	{
		i = 1;
		while (i < size && array[i - 1] > array[i]) // Lets just find the start of the list again
			i++;                        // But without getting to the last position
	}
	if (i == size) // If you did reach the last position, just stay there
		i = 0;
	return (i);
}

void    rotate_to_range(t_list)
{

}



t_instruction		*rotate(t_state *stt)
{
	t_instruction		*instr;
	size_t				mvt[2];
	size_t				min[2];
	size_t				min_mvt[2];

	mvt[0] = closer_pos_to_inf(stt->stack_a->array[0], stt->stack_b);
	min[0] = less_mvt_at_begin(mvt[0], &min_mvt[0], stt->stack_a, stt->stack_b);
	min[1] = less_mvt_at_end(mvt[0], &min_mvt[1], stt->stack_a, stt->stack_b);
	if (mvt[0] > stt->stack_b->size / 2)
		mvt[1] = stt->stack_b->size - mvt[0];
	else
		mvt[1] = mvt[0];
	if (stt->stack_a->size > 1 && (min[0] <= mvt[1] || min[1] <= mvt[1]))
		instr = rotate_a(stt, min, min_mvt);
	else if (mvt[0] > stt->stack_b->size / 2)
		instr = add_instruction(&stt->instructions, "rrb");
	else
		instr = add_instruction(&stt->instructions, "rb");
	return (instr);
}


void    insertion_sort(t_list **stack_a, t_list **stack_b)
{
    px('b', stack_a, stack_b, 1);
    px('b', stack_a, stack_b, 1);
    if ((*stack_b)->value < (*stack_b)->next->value)
        sx('b', stack_b, 1);

    int size = ft_lstsize(*stack_a);
    int i = 0;
    while (i < size)
    {
        int steps = find_number_range(stack_a, stack_b);
        if (steps != -1)
        {
            rotate_n_times(stack_b, steps, 'b');
            px('b', stack_a, stack_b, 1);
            if (i < 10)
                rotate_n_times(stack_b, steps * -1, 'b');
        }
        i++;
    }
    empty_stack(stack_b, stack_a, 'a', size + 2);
}


int find_number_range(t_list **stack_a, t_list **stack_b)
{
    int i;
    int size;
    unsigned int number;
    t_list *node;

    number = (*stack_a)->value;
    node = *stack_b;

    i = 0;
    size = ft_lstsize(*stack_b);
    t_list *prev = ft_lstlast(*stack_b);
    while (node != NULL && (node->value > number || prev->value < number))
    {
        i++;
        prev = node;
        node = node->next;
    }
    //printf("i: %d\n\t-> %u > x > y\n\n", i, (node == NULL) ? (-1) : node->value);

    if (node == NULL)
    {
        px('b', stack_a, stack_b, 1);
        rx('b', stack_b, 1);
        return (-1);
    }
    //if (i > ((size - i)))
    //    return (((size - i)) * -1);
    return (i);
}
*/
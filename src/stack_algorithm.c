#include <push_swap.h>

/*
    Stack Algorith
*/

#define CHUNK_SIZE 500 / 8

// ChunkSize 100 -> ~1745
// ChunkSize 500 / 8 -> ~1727

/*void    stack_sort(t_list **stack_a, t_list **stack_b)
{
    // Empty Stack A into Stack B in an ordered way
}
*/
unsigned int ft_abs(int n)
{
    if (n < 0)
        return (n * -1);
    return (n);
}

void    sort_and_empty_stack(t_list **stack_a, t_list **stack_b)
{
    unsigned int stack;
    unsigned int value;
    int size;
    int found;
    int chunk_size;

    size = ft_lstsize(*stack_a);
    if (size >= 250)
        chunk_size = 500 / 8;
    else
        chunk_size = size / 5;
    stack = 0;
    found = 0;
    while (*stack_a != NULL)
    {
        if ((*stack_a)->value < ((stack + 1) * chunk_size))
        {
            value = (*stack_a)->value;
            px('b', stack_a, stack_b, 1);
            found++;
            if (found >= chunk_size)
            {
                found = 0;
                stack++;
            }
            if (value >= (stack * chunk_size) + (chunk_size / 2))
            {
                if ((*stack_a) != NULL && (*stack_a)->value > ((stack + 1) * chunk_size))
                    rr(stack_a, stack_b);
                else
                    rx('b', stack_b, 1);
            }
            //printf("Found %u; (%d -> %d) [%d]\n", value, found, found + 1, (stack * chunk_size) + (chunk_size / 2));
        }
        else
            rx('a', stack_a, 1);
    }
    //int i = ft_lstsize(*stack_b) - 1;
    //int chamber = 0;
    long int highest = ft_lstsize(*stack_b) - 1;
    while (highest >= 0)
    {
        smart_rotate(stack_b, highest, 'b', 0);
        px('a', stack_b, stack_a, 1);
        highest--;
    }
    /*long int smallest = 0;
    //while (*stack_b != NULL)
    {
        //int high_len = find_number(*stack_b, (unsigned int) highest);
        //int small_len = find_number(*stack_b, (unsigned int) smallest);

        //if (ft_abs(high_len) > ft_abs(small_len) && smallest != -1)
        {
            smart_rotate(stack_b, smallest, 'b', 0);
            px('a', stack_b, stack_a, 1);
            rx('a', stack_a, 1);
            chamber++;
            smallest++;
            if (smallest >= highest)
                smallest = -1;
        //}
        //else
        {//
            smart_rotate(stack_b, highest, 'b', 0);
            px('a', stack_b, stack_a, 1);
            highest--;
        //}
    }
    smart_rotate(stack_a, 0, 'a', 0);*/
}


#include <push_swap.h>

/*
    Radix Sort Algorithm (Base 2)

    1. Check if the Stack A is sorted
        -> If it's sorted, go to #5
        -> If it's not sorted, go to #2
    2. Go through the stack A and push to B every number
        that has a '0' in the rightmost not-seen-before position (in binary)
    3. Push every number from Stack B to Stack A, until B is empty
    4. Go back to #1
    5. You're done
*/


// 50  -> 467
// 100 -> 1084   /  700
// 500 -> 6784   /  5500

void    radix_sort(t_list **stack_a, t_list **stack_b)
{
    int binary_position;
    int stack_len;

    binary_position = 0;
    while (!is_sorted(*stack_a))
    {
        stack_len = ft_lstsize(*stack_a);
        while (stack_len != 0)
        {
            if (((*stack_a)->value & (1 << binary_position)) == 0)
                px('b', stack_a, stack_b, 1);
            else
                rx('a', stack_a, 1);
            stack_len--;
        }
        empty_stack(stack_b, stack_a, 'a');
        binary_position++;
    }
}
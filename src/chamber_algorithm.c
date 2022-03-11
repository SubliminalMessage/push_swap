#include <push_swap.h>

/*
    Worst case:  ./push_swap 1 2 0 4 3 > output.txt && wc -l output.txt && rm output.txt

    Chamber Sort Algorithm

    1. Check if the stack A is sorted
        -> If it's sorted go to #6
        -> If it's not sorted, go to #2
    2. Bring the smallest number to the top of the stack
    3. Check if stack A is sorted (again)
        - If it's sorted, go to #6
        -> If it's not sorted, go to #4
    4. Push to B
    5. Go back to #1
    6. Push every number from Stack B to Stack A, until B is empty
    7. You're done
*/

void    chamber_sort(t_list **stack_a, t_list **stack_b)
{
    int smallest;
    int pushed;

    smallest = 0;
    pushed = 0;
    while (!is_sorted(*stack_a)) // #1
    {
        smart_rotate(stack_a, smallest, 'a', 1); // #2
        if (is_sorted(*stack_a)) // #3
            break ;
        px('b', stack_a, stack_b, 1); // #4
        pushed++;
        smallest++;
    }
    empty_stack(stack_b, stack_a, 'a', pushed); // #6
}
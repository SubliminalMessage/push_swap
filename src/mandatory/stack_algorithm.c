#include <push_swap.h>

/*
    Stack Algorithm
*/

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

    /*
        Chunk Size      Only Moves to B      All Moves (1-Depth)    All Moves (Both Sides)
        25              ~5100                 ~6800         
        50              ~2750                 ~5500
        65              ~2200                 ~5600                 ~5550
        75              ~2000                 ~5750
        100             ~1600                 ~6500
        125             ~1300                 ~7000
        150             ~1200                 ~7750
        175             ~1100                 ~8250
        200             ~1000                 ~9400
    */

    size = ft_lstsize(*stack_a);
    double multiplier = 0.25;;
    if (size >= 250)
    {
        chunk_size = 500 / 8;
        multiplier = 0.25;
    }
    else
    {
        chunk_size = size / 5;
        multiplier = 0.25;
    }
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
                    rr(stack_a, stack_b, 1);
                else
                    rx('b', stack_b, 1);
            }
            //printf("Found %u; (%d -> %d) [%d]\n", value, found, found + 1, (stack * chunk_size) + (chunk_size / 2));
        }
        else
            rx('a', stack_a, 1);
    }
    //int i = ft_lstsize(*stack_b) - 1;
    int chamber = 0;
    long int highest = ft_lstsize(*stack_b) - 1;
    /*while (highest >= 0)
    {
        smart_rotate(stack_b, highest, 'b', 0);
        px('a', stack_b, stack_a, 1);
        highest--;
    }*/
    long int smallest = highest - chunk_size;
    int min_chamber = smallest;
    while (*stack_b != NULL)
    {
        int high_len = find_number(*stack_b, (unsigned int) highest);
        int small_len = find_number(*stack_b, (unsigned int) smallest);

        //printf("High (%ld): %d / %d Low (%ld)\n", highest, ft_abs(high_len), ft_abs(small_len), smallest);
        if (smallest >= 0 && ft_abs(high_len) > ft_abs(small_len))
        {
            if (smallest < min_chamber)
                min_chamber = smallest;
            smart_rotate(stack_b, smallest, 'b', 0);
            px('a', stack_b, stack_a, 1);
            rx('a', stack_a, 1);
            chamber++;
            smallest++;
            //printf("Push Smallest. Now Chamber %d, smallest %ld\n", chamber, smallest);
        }
        else
        {
            //printf("Looking for %ld\n", highest);
            smart_rotate(stack_b, highest, 'b', 0);
            px('a', stack_b, stack_a, 1);
            if (smallest <= -1)
            {
                //printf("Smallest was -1, so rotating A %d times\n", chamber);
                while (chamber != 0)
                {
                    rrx('a', stack_a, 1);
                    chamber--;
                }
                //printf("Chamber is now %d\n", chamber);
            }
            highest--;
            if (smallest <= -1)
            {
                smallest = highest - (chunk_size * 0.25);
                if (highest > (min_chamber - 1))
                    highest = min_chamber - 1;
                //printf("Smallest now restored to %ld\n", smallest);
                //printf("Highest is now %ld (%d - 1)\n", highest, min_chamber);
            }
        }
         if (smallest >= highest)
                smallest = -1;
    }
    smart_rotate(stack_a, 0, 'a', 0);
}


#include <push_swap.h>

void    ss(t_list **stack_a, t_list **stack_b)
{
    sx('a', stack_a, 0);
    sx('b', stack_b, 0);
    write(1, "ss\n", 3);
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    rx('a', stack_a, 0);
    rx('b', stack_b, 0);
    write(1, "rr\n", 3);
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    rrx('a', stack_a, 0);
    rrx('b', stack_b, 0);
    write(1, "rrr\n", 4);
}
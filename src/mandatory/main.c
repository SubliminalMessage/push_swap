#include <push_swap.h>

#include <stdio.h>

// https://trello.com/b/ivhy0iec/pushswap
// https://numbergenerator.org/randomnumbergenerator
// https://www.notion.so/Push_swap-21758af851874d70a09c854ae200a0ae

// ARG=`perl -e "use List::Util 'shuffle'; print join(' ', shuffle(0..(5 - 1)))"` && ./push_swap $ARG > output.txt && wc -l output.txt && rm output.txt && echo $ARG && echo "\n\n"

int main(int argc, char **argv)
{
    t_list  *sorted;
    t_list  *stack_a;
    t_list  *stack_b;
    int     size;

    sorted = NULL;
    stack_a = NULL;
    stack_b = NULL;
    if (argc > 1)
    {
        parse_numbers(argc, argv, &sorted, &stack_a);
        merge_sort(&sorted);
        transfer_numbers(&sorted, &stack_a);
        size = ft_lstsize(sorted);
        //insertion_sort(&stack_a, &stack_b);
        if (size >= 50)
            sort_and_empty_stack(&stack_a, &stack_b);
        else
            chamber_sort(&stack_a, &stack_b);
        //print_stack(stack_a);
        //radix_sort(&stack_a, &stack_b);
        //print_stack(stack_b);

        //printf("Is sorted? -> %d\n", is_sorted(stack_a));
        clean_exit(&sorted, &stack_a, &stack_b, NULL);
    }
}

void    print_stack(t_list *stack)
{
    t_list *node;
    
    node = stack;
    printf("Stack\n------\n");
    while (node != NULL)
    {
        printf("%d -> %d\n", node->original, node->value);
        node = node->next;
    }
    printf("------\n");
}
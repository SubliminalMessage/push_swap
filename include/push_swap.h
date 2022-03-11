#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <common.h>

# include <stdio.h>

// parse_numbers.c
void    parse_numbers(int argc, char **argv, t_list **sort, t_list **stack);
void    print_stack(t_list *stack);

// merge_sort.c
void	merge_sort(t_list **root);

// calm_down.c
void    calm_number_down(t_list **root, int original, int value);
void    transfer_numbers(t_list **sorted, t_list **stack);

// stack_utils.c
void    smart_rotate(t_list **root, unsigned int find, char stack, int effic);
int     find_number(t_list *stack, unsigned int find);
void	rotate_n_times(t_list **root, int steps, char stack);
void	empty_stack(t_list **src, t_list **dst, char drop_at, int drop_count);
unsigned int	*to_array(t_list *stack);

// Algorithms
void    chamber_sort(t_list **stack_a, t_list **stack_b);
void    radix_sort(t_list **stack_a, t_list **stack_b);

void    sort_and_empty_stack(t_list **stack_a, t_list **stack_b);
void    insertion_sort(t_list **stack_a, t_list **stack_b);
#endif
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <common.h>

# include <stdio.h>

typedef unsigned int	t_uint;

// parse_numbers.c
void	parse_numbers(int argc, char **argv, t_list **sort, t_list **stack);
void	print_stack(t_list *stack);

// merge_sort.c
void	merge_sort(t_list **root);

// calm_down.c
void	calm_number_down(t_list **root, int original, int value);
void	transfer_numbers(t_list **sorted, t_list **stack);

// stack_utils.c
void	smart_rotate(t_list **root, unsigned int find, char stack, int effic);
int		find_number(t_list *stack, unsigned int find);
void	rotate_n_times(t_list **root, int steps, char stack);
void	empty_stack(t_list **src, t_list **dst, char drop_at, int drop_count);

// Algorithms
void	chamber_sort(t_list **stack_a, t_list **stack_b);
void	sort_and_empty_stack(t_list **stack_a, t_list **stack_b);

// Stack Algorithm Utils
t_uint	ft_abs(int n);
int		get_chunk_size(t_list **stack_a, t_list **stack_b);
void	restore_chamber(long *high, long *small, int *min, int chk_sz);
void	empty_chamber(long *small, int *chamber, t_list **stack_a);
long	triadic(int cond, long true_v, long false_v);
void	push_smallest(t_list **a, t_list **b, long *small, long high);
void	push_to_a(t_list **a, t_list **b, long number);
int	variable_setters(t_list *b, long *high, long *small, t_uint chk_sz);
#endif
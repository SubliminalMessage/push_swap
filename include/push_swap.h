#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <libft.h>

# include <stdio.h> // <??

// parse_numbers.c
void    parse_numbers(int argc, char **argv, t_list **sort, t_list **stack);
void    clean_exit(t_list **a, t_list **b, t_list **c, char *msg);
int     is_sorted(t_list *root);
int     are_duplicates(t_list *root);
void    print_stack(t_list *stack);

// basic_movements.c & combo_movements.c
void    sx(char stack, t_list **root, int print_text);
void    rx(char stack, t_list **root, int print_text);
void    rrx(char stack, t_list **root, int print_text);
void    px(char stack, t_list **src, t_list **dst, int print_text);
void    ss(t_list **stack_a, t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);

// merge_sort.c
void	merge_sort(t_list **root);

// calm_down.c
void    calm_number_down(t_list **root, int original, int value);
void    transfer_numbers(t_list **sorted, t_list **stack);

// stack_utils.c
void    smart_rotate(t_list **root, unsigned int find, char stack);
int     find_number(t_list *stack, unsigned int find, int len);
void	rotate_n_times(t_list **root, int steps, char stack);
void	empty_stack(t_list **src, t_list **dst, char drop_at);

// chamber_algorithm.c
void    chamber_sort(t_list **stack_a, t_list **stack_b);
#endif
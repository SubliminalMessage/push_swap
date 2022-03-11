#ifndef COMMON_H
# define COMMON_H

#include <libft.h>

// basic_movements.c & combo_movements.c
void    sx(char stack, t_list **root, int print_text);
void    rx(char stack, t_list **root, int print_text);
void    rrx(char stack, t_list **root, int print_text);
void    px(char stack, t_list **src, t_list **dst, int print_text);
void    ss(t_list **stack_a, t_list **stack_b, int print_text);
void    rr(t_list **stack_a, t_list **stack_b, int print_text);
void    rrr(t_list **stack_a, t_list **stack_b, int print_text);

// basic_utils.c
int     is_sorted(t_list *root);
int     are_duplicates(t_list *root);
void    clean_exit(t_list **a, t_list **b, t_list **c, char *msg);

#endif
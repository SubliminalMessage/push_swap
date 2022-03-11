#include <common.h>

void    sx(char stack, t_list **root, int print_text)
{
    t_list *first_node;
    t_list *second_node;

    if (root == NULL || *root == NULL || ft_lstsize(*root) == 1)
        return ;
    first_node = *root;
    second_node = first_node->next;
    first_node->next = second_node->next;
    second_node->next = first_node;
    *root = second_node;
    if (print_text)
    {
        write(1, "s", 1);
        write(1, &stack, 1);
        write(1, "\n", 1);
    }
}

void    rx(char stack, t_list **root, int print_text)
{
    t_list *first_node;

    if (root == NULL || *root == NULL || ft_lstsize(*root) == 1)
        return ;
    first_node = *root;
    *root = first_node->next;
    first_node->next = NULL;
    ft_lstadd_back(root, first_node);
    if (print_text)
    {
        write(1, "r", 1);
        write(1, &stack, 1);
        write(1, "\n", 1);
    }
}

void    rrx(char stack, t_list **root, int print_text)
{
    t_list *first_node;
    t_list *last_node;
    t_list *prev_node;

    if (root == NULL || *root == NULL || ft_lstsize(*root) == 1)
        return ;
    first_node = *root;
    last_node = ft_lstlast(*root);
    prev_node = first_node;
    while (prev_node->next != NULL && prev_node->next != last_node)
        prev_node = prev_node->next;
    prev_node->next = NULL;
    last_node->next = first_node;
    *root = last_node;
    if (print_text)
    {
        write(1, "rr", 2);
        write(1, &stack, 1);
        write(1, "\n", 1);
    }
}

void    px(char stack, t_list **src, t_list **dst, int print_text)
{
    t_list *first_node;

    if (src == NULL || *src == NULL)
        return ;
    if (ft_lstsize(*src) == 1)
    {
        ft_lstadd_front(dst, *src);
        *src = NULL;
    }
    else
    {
        first_node = *src;
        *src = first_node->next;
        first_node->next = NULL;
        ft_lstadd_front(dst, first_node);
    }
    if (print_text)
    {
        write(1, "p", 1);
        write(1, &stack, 1);
        write(1, "\n", 1);
    }
}
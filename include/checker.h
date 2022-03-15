#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <common.h>

void	parse_input(int argc, char **argv, t_list **stack);
void	execute_operation(char *op, t_list **stack_a, t_list **stack_b);

#endif
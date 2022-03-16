/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:11:54 by dangonza          #+#    #+#             */
/*   Updated: 2022/03/16 15:11:56 by dangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <common.h>

void	parse_input(int argc, char **argv, t_list **stack);
void	execute_operation(char *op, t_list **stack_a, t_list **stack_b);

#endif

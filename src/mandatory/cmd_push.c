/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:02:18 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/23 12:15:44 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_push *push_swap, t_cmd type, t_bool print_checker)
{
	if (type == pa)
	{
		execute_push(&push_swap->stack_a, \
					&push_swap->stack_b);
		if (print_checker)
			ft_printf("pa\n");
	}
	else if (type == pb)
	{
		execute_push(&push_swap->stack_b, \
					&push_swap->stack_a);
		if (print_checker)
			ft_printf("pb\n");
	}
}

// void	execute_push(t_stack **stack_1, t_stack **stack_2)
// {

// }

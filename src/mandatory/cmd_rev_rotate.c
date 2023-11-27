/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:32:34 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/27 12:12:28 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_push *push_swap, t_cmd type, t_bool print_checker)
{
	if (type == rra)
	{
		execute_rev_rotate(&push_swap->stack_a);
		if (print_checker)
			ft_printf("rra\n");
	}
	else if (type == rrb)
	{
		execute_rev_rotate(&push_swap->stack_b);
		if (print_checker)
			ft_printf("rrb\n");
	}
	else if (type == rrr)
	{
		execute_rev_rotate(&push_swap->stack_a);
		execute_rev_rotate(&push_swap->stack_b);
		if (print_checker)
			ft_printf("rrr\n");
	}
}

void	execute_rev_rotate(t_stack **stack)
{
	t_stack	*current_first;
	t_stack	*new_first;
	
	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(EXIT_FAILURE);
	current_first = *stack;
	new_first = find_last_node(*stack);
	new_first->prev->next = NULL;
	current_first->prev = new_first;
	new_first->prev = NULL;
	new_first->next = current_first;
	*stack = new_first;
}

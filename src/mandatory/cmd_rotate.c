/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:00:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/27 11:08:26 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_push *push_swap, t_cmd type, t_bool print_checker)
{
	if (type == ra)
	{
		execute_rotate(&push_swap->stack_a);
		if (print_checker)
			ft_printf("ra\n");
	}
	else if (type == rb)
	{
		execute_rotate(&push_swap->stack_b);
		if (print_checker)
			ft_printf("rb\n");
	}
	else if (type == rr)
	{
		execute_rotate(&push_swap->stack_a);
		execute_rotate(&push_swap->stack_b);
		if (print_checker)
			ft_printf("rr\n");
	}
}

void	execute_rotate(t_stack **stack)
{
	t_stack	*new_last;
	t_stack	*current_last;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(EXIT_FAILURE);
	new_last = *stack;
	current_last = find_last_node(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current_last->next = new_last;
	new_last->prev = current_last;
	new_last->next = NULL;
}

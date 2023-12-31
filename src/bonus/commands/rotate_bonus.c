/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:00:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/08 16:16:37 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	t_stack	*current_last;
	t_stack	*new_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	current_last = find_last_node(*stack);
	new_last = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current_last->next = new_last;
	new_last->prev = current_last;
	new_last->next = NULL;
}

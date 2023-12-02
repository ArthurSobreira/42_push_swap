/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:02:18 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/02 16:23:42 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	execute_push(t_stack **dst_stack, t_stack **src_stack)
{
	t_stack	*push_node;

	if (*src_stack == NULL)
		handle_error(EXIT_FAILURE);
	push_node = *src_stack;
	*src_stack = (*src_stack)->next;
	if (*src_stack != NULL)
		(*src_stack)->prev = NULL;
	push_node->prev = NULL;
	if (*dst_stack == NULL)
	{
		*dst_stack = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst_stack;
		(*dst_stack)->prev = push_node;
		*dst_stack = push_node;
	}
}

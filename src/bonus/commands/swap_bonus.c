/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:58:58 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/08 16:16:41 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_push *push_swap, t_cmd type, t_bool print_checker)
{
	if (type == sa)
	{
		execute_swap(&push_swap->stack_a);
		if (print_checker)
			ft_printf("sa\n");
	}
	else if (type == sb)
	{
		execute_swap(&push_swap->stack_b);
		if (print_checker)
			ft_printf("sb\n");
	}
	else if (type == ss)
	{
		execute_swap(&push_swap->stack_a);
		execute_swap(&push_swap->stack_b);
		if (print_checker)
			ft_printf("ss\n");
	}
}

void	execute_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	if (second->next != NULL)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
}

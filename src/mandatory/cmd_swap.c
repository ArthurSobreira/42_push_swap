/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:58:58 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/22 20:08:10 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, t_cmd type, t_bool print_checker)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_error(EXIT_FAILURE);
	first = *stack;
	second = first->next;
    first->next = second->next;
    if (second->next)
    	second->next->prev = first;
    second->prev = first->prev;
    if (first->prev)
        first->prev->next = second;
    first->prev = NULL;
    second->next = first;
    *stack = second;
	if (print_checker)
	{
		if (type == sa)
			ft_printf("sa\n");
		else if (type == sb)
			ft_printf("sb\n");
		else if (type == ss)
			ft_printf("ss\n");
	}
}

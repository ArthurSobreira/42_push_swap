/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:47:22 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/04 11:33:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack *stack)
{
	int	current_pos;
	int	center_line;

	if (stack == NULL)
		return ;
	current_pos = 0;
	center_line = stack_length(stack) / 2;
	while (stack != NULL)
	{
		stack->position = current_pos;
		if (current_pos <= center_line)
			stack->above_median = TRUE;
		else if (current_pos > center_line)
			stack->above_median = FALSE;
		stack = stack->next;
		++current_pos;
	}
}

void	smallest_to_top(t_push *push_swap)
{
	t_stack	*smallest_node;
	int		smallest_pos;

	set_position(push_swap->stack_a);
	smallest_pos = find_smallest_position(push_swap->stack_a);
	smallest_node = get_node(push_swap->stack_a, smallest_pos);
	if (smallest_node->above_median)
	{
		while (push_swap->stack_a->position != smallest_pos)
			rotate(push_swap, ra, TRUE);
	}
	else if (!smallest_node->above_median)
	{
		while (push_swap->stack_a->position != smallest_pos)
			reverse_rotate(push_swap, rra, TRUE);
	}
}

int	find_biggest_position(t_stack *stack)
{
	int	position;
	int	temp_max;

	position = 0;
	temp_max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > temp_max)
		{
			temp_max = stack->value;
			position = stack->position;
		}
		stack = stack->next;
	}
	return (position);
}

int	find_smallest_position(t_stack *stack)
{
	int	position;
	int	temp_min;

	position = 0;
	temp_min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < temp_min)
		{
			temp_min = stack->value;
			position = stack->position;
		}
		stack = stack->next;
	}
	return (position);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:47:22 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/30 11:06:34 by arsobrei         ###   ########.fr       */
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

short	find_high_position(t_stack *stack)
{
	short	position;
	int		temp_max;

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

short	find_low_position(t_stack *stack)
{
	short	position;
	int		temp_min;

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

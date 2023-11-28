/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:47:22 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/28 13:16:03 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

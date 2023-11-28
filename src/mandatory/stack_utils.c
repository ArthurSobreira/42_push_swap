/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:20:53 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/28 10:48:23 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_ordered(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		handle_error(EXIT_FAILURE);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

size_t	stack_length(t_stack *stack)
{
	size_t	length;

	if (stack == NULL)
		handle_error(EXIT_FAILURE);
	length = 1;
	while (stack->next != NULL)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

void	set_position(t_stack *stack)
{
	int	current_pos;

	if (stack == NULL)
		handle_error(EXIT_FAILURE);
	current_pos = 0;
	while (stack != NULL)
	{
		stack->position = current_pos;
		stack = stack->next;
		++current_pos;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (stack != NULL)
	{
		while (*stack)
		{
			temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
		*stack = NULL;
	}
}

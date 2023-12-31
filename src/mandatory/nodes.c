/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:37:15 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/06 14:25:51 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		handle_error(EXIT_FAILURE);
	new_node->value = value;
	new_node->position = 0;
	new_node->price = 0;
	new_node->above_center = FALSE;
	new_node->cheapest = FALSE;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->match_node = NULL;
	return (new_node);
}

t_stack	*find_last_node(t_stack *stack)
{
	if (stack == NULL)
		handle_error(EXIT_FAILURE);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_node(t_stack *stack, int position)
{
	while (stack != NULL)
	{
		if (stack->position == position)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

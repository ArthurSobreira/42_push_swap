/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:37:15 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/02 16:57:55 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	link_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = create_node(value);
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		handle_error(EXIT_FAILURE);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
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

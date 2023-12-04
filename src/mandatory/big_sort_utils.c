/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:13:37 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/04 18:42:57 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_match_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*match_node;
	int		current_best;

	while (stack_b != NULL)
	{
		current_best = INT_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value \
				&& current_a->value < current_best)
			{
				current_best = current_a->value;
				match_node = current_a;
			}
			current_a = current_a->next;
		}
		if (current_best != INT_MAX)
			stack_b->match_node = match_node;
		else
			stack_b->match_node = get_node(stack_a, \
			find_smallest_position(stack_a));
		stack_b = stack_b->next;
	}
}

void	set_price(t_stack *stack_a, t_stack *stack_b)
{
	size_t	len_a;
	size_t	len_b;
	int		price;

	len_a = stack_length(stack_a);
	len_b = stack_length(stack_b);
	price = 0;
	while (stack_b != NULL)
	{
		if (stack_b->above_median)
			price = stack_b->position;
		else
			price = len_b - stack_b->position;
		price += get_match_node_price(stack_b, len_a);
		stack_b->price = price;
		stack_b = stack_b->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	int		cheapest_price;
	t_stack	*cheapest_node;

	if (stack == NULL)
		return ;
	cheapest_price = INT_MAX;
	while (stack != NULL)
	{
		if (stack->price < cheapest_price)
		{
			cheapest_price = stack->price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = TRUE;
}

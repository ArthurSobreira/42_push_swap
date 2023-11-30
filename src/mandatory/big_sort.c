/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:17:09 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/30 19:22:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	set_price(t_stack *stack_b);

void	big_sort(t_push *push_swap)
{
	short	smallest_pos;

	while (push_swap->length_a > 3)
	{
		push(push_swap, pb, TRUE);
		push_swap->length_a--;
	}
	if (!is_ordered(push_swap->stack_a))
		sort_three(push_swap);
	while (push_swap->stack_b)
	{
		set_position(push_swap->stack_a);
		set_position(push_swap->stack_b);
		set_match_node(push_swap->stack_a, push_swap->stack_b);
		// set_price(push_swap->stack_b);

		push_swap->stack_b = push_swap->stack_b->next;
	}
	smallest_pos = find_smallest_position(push_swap->stack_a);
	if (push_swap->stack_a->position != smallest_pos)
		smallest_to_top(push_swap);
}

// void	set_price(t_stack *stack_b)
// {
// 	while (stack_b != NULL)
// 	{
// 		/* code */
// 	}
	
// }

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

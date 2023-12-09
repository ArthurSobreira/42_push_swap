/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:17:09 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/08 13:47:18 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_push *push_swap)
{
	t_stack	*smallest_node;
	int		smallest_pos;

	send_everything_to_b(push_swap);
	if (!is_ordered(push_swap->stack_a))
		sort_three(push_swap);
	while (push_swap->stack_b != NULL)
	{
		set_position(push_swap->stack_a);
		set_position(push_swap->stack_b);
		set_match_node(push_swap->stack_a, push_swap->stack_b);
		set_price(push_swap->stack_a, push_swap->stack_b);
		set_cheapest(push_swap->stack_b);
		cheapest_to_top(push_swap);
		push(push_swap, pa, TRUE);
	}
	set_position(push_swap->stack_a);
	smallest_pos = find_smallest_position(push_swap->stack_a);
	smallest_node = get_node(push_swap->stack_a, smallest_pos);
	while (push_swap->stack_a != smallest_node)
		finalize_sorting(push_swap, smallest_node, a);
}

void	send_everything_to_b(t_push *push_swap)
{
	t_stack	*second_bigger;
	t_stack	*biggest_node;
	t_stack	*smallest_node;
	int		biggest_pos;
	int		smallest_pos;

	second_bigger = get_second_bigger(push_swap->stack_a);
	biggest_pos = find_biggest_position(push_swap->stack_a);
	biggest_node = get_node(push_swap->stack_a, biggest_pos);
	smallest_pos = find_smallest_position(push_swap->stack_a);
	smallest_node = get_node(push_swap->stack_a, smallest_pos);
	while (push_swap->length_a > 3)
	{
		if (push_swap->stack_a == biggest_node || \
			push_swap->stack_a == second_bigger || \
			push_swap->stack_a == smallest_node)
			rotate(push_swap, ra, TRUE);
		push(push_swap, pb, TRUE);
		push_swap->length_a--;
	}
}

void	cheapest_to_top(t_push *push_swap)
{
	t_stack	*cheapest;
	t_stack	*cheapest_match;

	cheapest = get_cheapest(push_swap->stack_b);
	cheapest_match = cheapest->match_node;
	if ((cheapest->above_center) && (cheapest_match->above_center))
	{
		while ((push_swap->stack_a != cheapest->match_node) && \
			(push_swap->stack_b != cheapest))
			rotate(push_swap, rr, TRUE);
	}
	else if (!(cheapest->above_center) && !(cheapest_match->above_center))
	{
		while ((push_swap->stack_a != cheapest->match_node) && \
			(push_swap->stack_b != cheapest))
			reverse_rotate(push_swap, rrr, TRUE);
	}
	while (push_swap->stack_a != cheapest_match)
		finalize_sorting(push_swap, cheapest_match, a);
	while (push_swap->stack_b != cheapest)
		finalize_sorting(push_swap, cheapest, b);
}

void	finalize_sorting(t_push *push_swap, t_stack *top_node, t_name name)
{
	if (name == a)
	{
		if (top_node->above_center)
			rotate(push_swap, ra, TRUE);
		else if (!(top_node->above_center))
			reverse_rotate(push_swap, rra, TRUE);
	}
	else if (name == b)
	{
		if (top_node->above_center)
			rotate(push_swap, rb, TRUE);
		else if (!(top_node->above_center))
			reverse_rotate(push_swap, rrb, TRUE);
	}
}

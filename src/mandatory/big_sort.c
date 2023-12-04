/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:17:09 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/04 19:59:54 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		set_price(push_swap->stack_a, push_swap->stack_b);
		set_cheapest(push_swap->stack_b);
		push_swap->stack_b = push_swap->stack_b->next;
	}
	smallest_pos = find_smallest_position(push_swap->stack_a);
	if (push_swap->stack_a->position != smallest_pos)
		smallest_to_top(push_swap);
}

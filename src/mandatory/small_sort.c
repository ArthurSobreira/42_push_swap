/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:03:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/02 17:42:21 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_push *push_swap)
{
	if (push_swap->length_a == 2)
		swap(push_swap, sa, TRUE);
	else if (push_swap->length_a == 3)
		sort_three(push_swap);
	else
		sort_few_elements(push_swap);
}

void	sort_three(t_push *push_swap)
{
	short	smallest_pos;
	short	biggest_pos;

	set_position(push_swap->stack_a);
	smallest_pos = find_smallest_position(push_swap->stack_a);
	biggest_pos = find_biggest_position(push_swap->stack_a);
	if (smallest_pos == 0)
	{
		reverse_rotate(push_swap, rra, TRUE);
		swap(push_swap, sa, TRUE);
	}
	else if (smallest_pos == 1)
	{
		if (biggest_pos == 0)
			rotate(push_swap, ra, TRUE);
		else
			swap(push_swap, sa, TRUE);
	}
	else if (smallest_pos == 2)
	{
		if (biggest_pos == 0)
			swap(push_swap, sa, TRUE);
		reverse_rotate(push_swap, rra, TRUE);
	}
}

void	sort_few_elements(t_push *push_swap)
{
	short	smallest_pos;

	while (stack_length(push_swap->stack_a) != 3)
	{
		smallest_pos = find_smallest_position(push_swap->stack_a);
		if (push_swap->stack_a->position != smallest_pos)
			smallest_to_top(push_swap);
		push(push_swap, pb, TRUE);
	}
	if (!is_ordered(push_swap->stack_a))
		sort_three(push_swap);
	while (push_swap->stack_b != NULL)
		push(push_swap, pa, TRUE);
}

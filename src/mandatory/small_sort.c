/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:03:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/30 12:22:05 by arsobrei         ###   ########.fr       */
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
	short	smaller_pos;
	short	bigger_pos;

	set_position(push_swap->stack_a);
	smaller_pos = find_smaller_position(push_swap->stack_a);
	bigger_pos = find_bigger_position(push_swap->stack_a);
	if (smaller_pos == 0)
	{
		rev_rotate(push_swap, rra, TRUE);
		swap(push_swap, sa, TRUE);
	}
	else if (smaller_pos == 1)
	{
		if (bigger_pos == 0)
			rotate(push_swap, ra, TRUE);
		else
			swap(push_swap, sa, TRUE);
	}
	else if (smaller_pos == 2)
	{
		if (bigger_pos == 0)
			swap(push_swap, sa, TRUE);
		rev_rotate(push_swap, rra, TRUE);
	}
}

void	sort_few_elements(t_push *push_swap)
{
	short	smaller_pos;
	t_stack	*smaller_node;

	while (stack_length(push_swap->stack_a) != 3)
	{
		set_position(push_swap->stack_a);
		smaller_pos = find_smaller_position(push_swap->stack_a);
		smaller_node = get_node(push_swap->stack_a, smaller_pos);
		if (smaller_node->above_median)
		{
			while (push_swap->stack_a->position != smaller_pos)
				rotate(push_swap, ra, TRUE);
		}
		else if (!smaller_node->above_median)
		{
			while (push_swap->stack_a->position != smaller_pos)
				rev_rotate(push_swap, rra, TRUE);
		}
		push(push_swap, pb, TRUE);
	}
	if (!is_ordered(push_swap->stack_a))
		sort_three(push_swap);
	while (push_swap->stack_b != NULL)
		push(push_swap, pa, TRUE);
}

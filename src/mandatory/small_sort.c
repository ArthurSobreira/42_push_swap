/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:03:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/28 10:52:55 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_push *push_swap)
{
	if (push_swap->length_a == 2)
		swap(push_swap, sa, TRUE);
	else if (push_swap->length_a == 3)
		sort_three(push_swap);
}

void	sort_three(t_push *push_swap)
{
	t_stack	*stack_a;
	short	lowest_pos;
	short	highest_pos;

	stack_a = push_swap->stack_a;
	lowest_pos = find_low_position(stack_a);
	highest_pos = find_high_position(stack_a);
	if (lowest_pos == 0)
	{
		rev_rotate(push_swap, rra, TRUE);
		swap(push_swap, sa, TRUE);
	}
	else if (lowest_pos == 1)
	{
		if (highest_pos == 0)
			rotate(push_swap, ra, TRUE);
		else
			swap(push_swap, sa, TRUE);
	}
	else if (lowest_pos == 2)
	{
		if (highest_pos == 0)
			swap(push_swap, sa, TRUE);
		rev_rotate(push_swap, rra, TRUE);
	}
}

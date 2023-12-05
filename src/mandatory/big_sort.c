/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:17:09 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/05 19:03:42 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_push *push_swap)
{
	t_stack	*smallest_node;
	int		smallest_pos;

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
		cheapest_to_top(&push_swap->stack_a, &push_swap->stack_b);
		push(push_swap, pa, TRUE);
	}
	set_position(push_swap->stack_a);
	smallest_pos = find_smallest_position(push_swap->stack_a);
	smallest_node = get_node(push_swap->stack_a, smallest_pos);
	while (push_swap->stack_a != smallest_node)
		finalize_sorting_a(&push_swap->stack_a, smallest_node);
}

void	cheapest_to_top(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	t_stack	*cheapest_match;

	cheapest = get_cheapest(*stack_b);
	cheapest_match = cheapest->match_node;
	if ((cheapest->above_center) && (cheapest_match->above_center))
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_center) && !(cheapest_match->above_center))
		rrotate_both(stack_a, stack_b, cheapest);
	while (*stack_a != cheapest_match)
		finalize_sorting_a(stack_a, cheapest_match);
	while (*stack_b != cheapest)
		finalize_sorting_b(stack_b, cheapest);
}

void	finalize_sorting_a(t_stack **stack, t_stack *top_node)
{
	if (top_node->above_center)
	{
		execute_rotate(stack);
		ft_printf("ra\n");
	}
	else if (!(top_node->above_center))
	{
		execute_reverse_rotate(stack);
		ft_printf("rra\n");
	}
}

void	finalize_sorting_b(t_stack **stack, t_stack *top_node)
{
	if (top_node->above_center)
	{
		execute_rotate(stack);
		ft_printf("rb\n");
	}
	else if (!(top_node->above_center))
	{
		execute_reverse_rotate(stack);
		ft_printf("rrb\n");
	}
}

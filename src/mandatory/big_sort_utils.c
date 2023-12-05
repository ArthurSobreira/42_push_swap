/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:13:37 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/05 20:01:51 by arsobrei         ###   ########.fr       */
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
	t_stack	*head;
	size_t	len_a;
	size_t	len_b;
	int		price;

	head = stack_b;
	len_a = stack_length(stack_a);
	len_b = stack_length(stack_b);
	price = 0;
	while (stack_b != NULL)
	{
		if (stack_b->above_center)
			price = stack_b->position;
		else
			price = len_b - stack_b->position;
		price += get_match_node_price(stack_b, len_a);
		if (stack_b == get_node(head, find_biggest_position(head)))
			price -= 1;
		else if (stack_b == get_node(head, find_smallest_position(head)))
			price += 1;
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

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while ((*stack_a != cheapest->match_node) && (*stack_b != cheapest))
	{
		execute_rotate(stack_a);
		execute_rotate(stack_b);
		ft_printf("rr\n");
	}
	set_position(*stack_a);
	set_position(*stack_b);
}

void	rrotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while ((*stack_a != cheapest->match_node) && (*stack_b != cheapest))
	{
		execute_reverse_rotate(stack_a);
		execute_reverse_rotate(stack_b);
		ft_printf("rrr\n");
	}
	set_position(*stack_a);
	set_position(*stack_b);
}

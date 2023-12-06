/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:13:37 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/06 17:26:54 by arsobrei         ###   ########.fr       */
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
		if (stack_b == get_node(head, find_biggest_position(head)) || \
			stack_b == get_second_bigger(head) || \
			stack_b == get_third_bigger(head))
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

t_stack	*get_second_bigger(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*second_bigger;

	biggest = get_node(stack, find_biggest_position(stack));
	second_bigger = NULL;
	while (stack != NULL)
	{
		if ((stack != biggest) && (second_bigger == NULL
				|| stack->value > second_bigger->value))
			second_bigger = stack;
		stack = stack->next;
	}
	return (second_bigger);
}

t_stack	*get_third_bigger(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*second_bigger;
	t_stack	*third_bigger;

	biggest = get_node(stack, find_biggest_position(stack));
	second_bigger = get_second_bigger(stack);
	third_bigger = NULL;
	while (stack != NULL)
	{
		if ((stack != biggest) && (stack != second_bigger) && \
			(third_bigger == NULL || stack->value > third_bigger->value))
			third_bigger = stack;
		stack = stack->next;
	}
	return (third_bigger);
}

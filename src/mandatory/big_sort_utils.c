/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:13:37 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/04 18:37:50 by arsobrei         ###   ########.fr       */
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

		ft_printf("b->value: %d\n", stack_b->value);
		ft_printf("\033[32mb->price\033[0m: %d\n", stack_b->price);
		ft_printf("b->target_node->value: %d\n", stack_b->match_node->value);
		if (stack_b->above_median)
			ft_printf("b->above_median: true\n\n");
		else
			ft_printf("b->above_median: false\n\n");

		stack_b = stack_b->next;
	}
}

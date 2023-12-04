/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:35:57 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/04 20:15:19 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // Delete later

void	print_elements(t_stack *stack, char title)
{
	printf("                        STACK %c                       \n", title);
	printf("|-----------------|-----------------|-----------------|\n");
	printf("| %-15s | %-15s | %-15s |\n", "prev->value", "value",
		"next->value");
	printf("|-----------------|-----------------|-----------------|\n");
	while (stack)
	{
		printf("| %-15d | [%d]: %-10d | %-15d |\n",
			(stack->prev != NULL) ? stack->prev->value : 0x0,
			stack->position,
			stack->value,
			(stack->next != NULL) ? stack->next->value : 0x0);
		stack = stack->next;
		if (stack != NULL)
			printf("|-----------------|-----------------|-----------------|\n");
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_push	*push_swap;

	if (argc == 1)
		handle_error(EXIT_NO_ARGS);
	else
	{
		push_swap = init_push_swap(argc, argv);
		validate_args(push_swap);
		init_stack(push_swap);
		// print_elements(push_swap->stack_a, 'A');
		if (!is_ordered(push_swap->stack_a))
		{
			if (push_swap->length_a <= 10)
				small_sort(push_swap);
			else
				big_sort(push_swap);
		}
		// print_elements(push_swap->stack_a, 'A');
		// print_elements(push_swap->stack_b, 'B');
		clear_all(push_swap, EXIT_SUCCESS);
	}
	return (0);
}

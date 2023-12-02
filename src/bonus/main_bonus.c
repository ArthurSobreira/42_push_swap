/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:35:57 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/02 18:12:35 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
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
		printf("| %-15d | %-15d | %-15d |\n",
			(stack->prev != NULL) ? stack->prev->value : 0x0,
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
		read_commands(push_swap);
		clear_all(push_swap, EXIT_SUCCESS);
	}
	return (0);
}

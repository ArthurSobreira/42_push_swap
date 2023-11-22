/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:35:57 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/22 20:06:54 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_elements(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
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
		if (!is_ordered(push_swap->stack_a))
		{
			if (push_swap->length_a <= 5)
				small_sort(push_swap);
		}
		print_elements(push_swap->stack_a);
		clear_all(push_swap, EXIT_SUCCESS);
	}
	return (0);
}

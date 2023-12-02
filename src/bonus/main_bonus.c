/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:35:57 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/02 17:46:53 by arsobrei         ###   ########.fr       */
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

void	execute_commands(t_push *push_swap, char *command)
{
	if (!ft_strncmp(command, "sa", 3))
		swap(push_swap, sa, TRUE);
	else if (!ft_strncmp(command, "sb", 3))
		swap(push_swap, sb, TRUE);
	else if (!ft_strncmp(command, "ss", 3))
		swap(push_swap, ss, TRUE);
	else if (!ft_strncmp(command, "pa", 3))
		push(push_swap, pa, TRUE);
	else if (!ft_strncmp(command, "pb", 3))
		push(push_swap, pb, TRUE);
	else if (!ft_strncmp(command, "ra", 3))
		rotate(push_swap, ra, TRUE);
	else if (!ft_strncmp(command, "rb", 3))
		rotate(push_swap, rb, TRUE);
	else if (!ft_strncmp(command, "rr", 3))
		rotate(push_swap, rr, TRUE);
	else if (!ft_strncmp(command, "rra", 4))
		reverse_rotate(push_swap, rra, TRUE);
	else if (!ft_strncmp(command, "rrb", 4))
		reverse_rotate(push_swap, rrb, TRUE);
	else if (!ft_strncmp(command, "rrr", 4))
		reverse_rotate(push_swap, rrr, TRUE);
	else
		handle_error(EXIT_FAILURE);
}

void	read_commands(t_push *push_swap)
{
	char	*command;
	int		counter;
	
	counter = 1;
	while (TRUE)
	{
		ft_printf("\033[35;3m%dst command\033[0m> ", counter);
		command = get_next_line(STDIN_FILENO);
		if (command == NULL)
			break ;
		execute_commands(push_swap, command);
		counter++;
	}
	if (is_ordered(push_swap->stack_a) && push_swap->stack_b == NULL)
		ft_printf("\033[32;1mOK\033[0m\n");
	else
		ft_printf("\033[31;1mKO\033[0m\n");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/12/02 18:12:01 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/02 18:12:01 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_commands(t_push *push_swap)
{
	char	*command;
	int		counter;
	size_t	len;

	counter = 1;
	while (TRUE)
	{
		ft_printf("\033[34;3m%dst command\033[0m\033[37;3m>\033[0m ",
			counter++);
		command = get_next_line(STDIN_FILENO);
		if (command == NULL)
			break ;
		execute_commands(push_swap, command);
		free(command);
	}
	len = stack_length(push_swap->stack_a);
	if ((is_ordered(push_swap->stack_a)) && (len == push_swap->length_a)
		&& (push_swap->stack_b == NULL))
		ft_printf("\n\033[32;1mOK\033[0m\n");
	else
		ft_printf("\n\033[31;1mKO\033[0m\n");
}

void	execute_commands(t_push *push_swap, char *command)
{
	if (!ft_strncmp(command, "sa\n", 3))
		swap(push_swap, sa, FALSE);
	else if (!ft_strncmp(command, "sb\n", 3))
		swap(push_swap, sb, FALSE);
	else if (!ft_strncmp(command, "ss\n", 3))
		swap(push_swap, ss, FALSE);
	else if (!ft_strncmp(command, "pa\n", 3))
		push(push_swap, pa, FALSE);
	else if (!ft_strncmp(command, "pb\n", 3))
		push(push_swap, pb, FALSE);
	else if (!ft_strncmp(command, "ra\n", 3))
		rotate(push_swap, ra, FALSE);
	else if (!ft_strncmp(command, "rb\n", 3))
		rotate(push_swap, rb, FALSE);
	else if (!ft_strncmp(command, "rr\n", 3))
		rotate(push_swap, rr, FALSE);
	else if (!ft_strncmp(command, "rra\n", 4))
		reverse_rotate(push_swap, rra, FALSE);
	else if (!ft_strncmp(command, "rrb\n", 4))
		reverse_rotate(push_swap, rrb, FALSE);
	else if (!ft_strncmp(command, "rrr\n", 4))
		reverse_rotate(push_swap, rrr, FALSE);
	else
		clear_invalid_command(push_swap, command);
}

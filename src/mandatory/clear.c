/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:15:20 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/08 16:22:35 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(short exit_code)
{
	if (exit_code == EXIT_FAILURE)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(exit_code);
}

void	clear_all(t_push *push_swap, short exit_code)
{
	if (push_swap->argv && push_swap->argv_checker == TRUE)
		free_split(push_swap->argv);
	if (push_swap->stack_a)
		free_stack(&push_swap->stack_a);
	if (push_swap->stack_b)
		free_stack(&push_swap->stack_b);
	free(push_swap);
	handle_error(exit_code);
}

void	free_split(char **split)
{
	size_t	index;

	index = 0;
	while (split[index] != NULL)
	{
		free(split[index]);
		index++;
	}
	free(split);
}

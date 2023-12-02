/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:15:20 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/02 16:23:34 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	handle_error(short exit_code)
{
	if (exit_code == 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	clear_all(t_push *push_swap, short exit_code)
{
	if (push_swap->argv && push_swap->argv_checker == TRUE)
		free_split(push_swap->argv);
	if (push_swap->stack_a)
		free_stack(&push_swap->stack_a);
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
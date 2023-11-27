/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:19:38 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/27 18:45:05 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*init_push_swap(int argc, char *argv[])
{
	t_push	*push_swap;

	push_swap = (t_push *)malloc(sizeof(t_push));
	if (!push_swap)
		handle_error(-1);
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->length_a = 0;
	push_swap->length_b = 0;
	push_swap->argv_checker = FALSE;
	if (argc == 2)
	{
		push_swap->argv = ft_split(argv[1], ' ');
		push_swap->argv_checker = TRUE;
	}
	else
		push_swap->argv = ++argv;
	return (push_swap);
}

void	init_stack(t_push *push_swap)
{
	size_t	index;
	int		value;

	index = 0;
	value = 0;
	while (push_swap->argv[index])
	{
		value = ft_atoi(push_swap->argv[index]);
		link_node(&push_swap->stack_a, value);
		index++;
	}
	push_swap->length_a = stack_length(push_swap->stack_a);
	set_position(push_swap->stack_a);
}

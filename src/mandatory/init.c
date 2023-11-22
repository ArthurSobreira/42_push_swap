/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:19:38 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/22 14:53:08 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*init_push_swap(int argc, char *argv[])
{
	t_push	*push_swap;

	push_swap = (t_push *)malloc(sizeof(t_push));
	if (!push_swap)
		handle_error(-1);
	push_swap->a = NULL;
	push_swap->b = NULL;
	push_swap->split_checker = FALSE;
	if (argc == 2)
	{
		push_swap->argv = ft_split(argv[1], ' ');
		push_swap->split_checker = TRUE;
	}
	else
		push_swap->argv = ++argv;
	return (push_swap);
}

// t_stack	*init_stack(t_push *push_swap)
// {
// 	size_t	index;
// 	int		number;

// 	index = 0;
// 	number = 0;
// 	while (push_swap->argv[index])
// 	{
// 		number = ft_atoi(push_swap->argv[index]);
// 		push_swap->a = push(push_swap->a, number);
// 		index++;
// 	}
// }

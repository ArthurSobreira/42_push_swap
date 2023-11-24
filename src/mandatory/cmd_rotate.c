/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:00:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/24 17:28:07 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_push *push_swap, t_cmd type, t_bool print_checker)
{
	if (type == ra)
	{
		execute_rotate(&push_swap->stack_a);
		if (print_checker)
			ft_printf("ra\n");
	}
	else if (type == rb)
	{
		execute_rotate(&push_swap->stack_b);
		if (print_checker)
			ft_printf("rb\n");
	}
	else if (type == rr)
	{
		execute_rotate(&push_swap->stack_a);
		execute_rotate(&push_swap->stack_b);
		if (print_checker)
			ft_printf("rr\n");
	}
}

void	execute_rotate(t_stack **stack)
{
	(void)stack;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:19:38 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/21 14:21:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*init_push_swap(void)
{
	t_push	*push_swap;

	push_swap = (t_push *)malloc(sizeof(t_push));
	if (!push_swap)
		handle_error(-1);
	push_swap->argv = NULL;
	push_swap->a = NULL;
	push_swap->b = NULL;
	push_swap->checker = FALSE;
	return (push_swap);
}

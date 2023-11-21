/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:19:38 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/21 11:44:28 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*init_push_swap(void)
{
	t_push	*ps;

	ps = (t_push *)malloc(sizeof(t_push));
	if (!ps)
		handle_error(-1);
	ps->argv = NULL;
	ps->a = NULL;
	ps->b = NULL;
	ps->checker = FALSE;
	return (ps);
}

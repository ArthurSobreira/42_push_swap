/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:17:09 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/30 12:01:26 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_push *push_swap)
{
	while (push_swap->length_a > 3)
	{
		push(push_swap, pb, TRUE);
		push_swap->length_a--;
	}
}

void	big_sort(t_push *push_swap)
{
	send_to_b(push_swap);
	sort_three(push_swap);
}

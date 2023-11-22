/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:03:11 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/22 20:04:26 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_push *push_swap)
{
	if (push_swap->length_a == 2)
		swap(&push_swap->stack_a, sa, TRUE);
	// else if (push_swap->length_a == 3)
	// 	sort_three(push_swap);
	// else if (push_swap->length_a == 4)
	// 	sort_four(push_swap);
	// else if (push_swap->length_a == 5)
	// 	sort_five(push_swap);
}

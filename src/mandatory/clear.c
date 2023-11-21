/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:15:20 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/21 11:45:15 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_all(t_push *push_swap, short exit_code)
{
	// if (push_swap->a)
	// 	clear_stack(push_swap->a);
	// if (push_swap->b)
	// 	clear_stack(push_swap->b);
	if (push_swap->argv && push_swap->checker == TRUE)
		free_split(push_swap->argv);
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

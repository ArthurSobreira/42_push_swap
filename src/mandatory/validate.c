/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:15:04 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/21 16:15:44 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_args(t_push *push_swap)
{
	size_t	index;
	long	number;

	if (*push_swap->argv == NULL)
		clear_all(push_swap, EXIT_FAILURE);
	index = 0;
	number = 0;
	while (push_swap->argv[index])
	{
		// ft_printf("argv[%d] = %s\n", index, push_swap->argv[index]);
		if (!valid_sintax(push_swap->argv[index]))
			clear_all(push_swap, EXIT_FAILURE);
		number = ft_atol(push_swap->argv[index]);
		if (number > INT_MAX || number < INT_MIN)
			clear_all(push_swap, EXIT_FAILURE);
		index++;
	}
}

t_bool	valid_sintax(char *number)
{
	size_t	index;
	t_bool	valid;

	index = 0;
	valid = TRUE;
	while (number[index])
	{
		if ((number[index] == '-' && !ft_isdigit(number[index + 1])) || \
			(number[index] == '+' && !ft_isdigit(number[index + 1])))
			valid = FALSE;
		else if (!ft_isdigit(number[index]))
		{
			if (number[index] != '-' && number[index] != '+')
				valid = FALSE;
		}
		index++;
	}
	return (valid);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:15:04 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/09 12:51:31 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_args(t_push *push_swap)
{
	size_t	index;
	long	number;

	if (!check_duplication(push_swap->argv) || *push_swap->argv == NULL)
		clear_all(push_swap, EXIT_FAILURE);
	index = 0;
	number = 0;
	while (push_swap->argv[index])
	{
		if (!check_sintax(push_swap->argv[index]))
			clear_all(push_swap, EXIT_FAILURE);
		number = ft_atol(push_swap->argv[index]);
		if (number > INT_MAX || number < INT_MIN)
			clear_all(push_swap, EXIT_FAILURE);
		index++;
	}
}

t_bool	check_duplication(char *args_list[])
{
	size_t	index;
	size_t	index2;
	long	number;

	index = 0;
	while (args_list[index])
	{
		number = ft_atol(args_list[index]);
		index2 = index + 1;
		while (args_list[index2])
		{
			if (number == ft_atol(args_list[index2]))
				return (FALSE);
			index2++;
		}
		index++;
	}
	return (TRUE);
}

t_bool	check_sintax(char *number)
{
	size_t	index;
	t_bool	valid;

	index = 0;
	valid = TRUE;
	if (number[index] == '\0')
		valid = FALSE;
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

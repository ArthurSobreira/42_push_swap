/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:35:57 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/20 18:00:09 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2 || !argv[1][0])
		handle_error(1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	while (*argv)
	{
		if (ft_isdigit(**argv))
			ft_putendl_fd(*argv, STDOUT_FILENO);
		argv++;
	}
	return (0);
}

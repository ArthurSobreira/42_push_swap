/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:41:22 by arsobrei          #+#    #+#             */
/*   Updated: 2023/11/22 14:52:39 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define EXIT_NO_ARGS -1
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_push
{
	t_stack	*a;
	t_stack	*b;
	t_bool	split_checker;
	char	**argv;
}				t_push;

t_push	*init_push_swap(int argc, char *argv[]);

void	validate_args(t_push *push_swap);
t_bool	check_sintax(char *number);
t_bool	check_duplication(char *args_list[]);

void	clear_all(t_push *push_swap, short exit_code);
void	handle_error(short exit_code);
void	free_split(char **split);

#endif
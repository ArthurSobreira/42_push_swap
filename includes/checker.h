/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:20:10 by arsobrei          #+#    #+#             */
/*   Updated: 2023/12/02 16:20:10 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

typedef enum e_cmd
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_cmd;

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_push
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv;
	t_bool	argv_checker;
	size_t	length_a;
	size_t	length_b;
}				t_push;

// Init Functions
t_push	*init_push_swap(int argc, char *argv[]);
void	init_stack(t_push *push_swap);

// Validate Functions
void	validate_args(t_push *push_swap);
t_bool	check_duplication(char *args_list[]);
t_bool	check_sintax(char *number);

// Node Functions
void	link_node(t_stack **stack, int value);
t_stack	*create_node(int value);
t_stack	*find_last_node(t_stack *stack);

// Stack Functions
t_bool	is_ordered(t_stack *stack);
size_t	stack_length(t_stack *stack);
void	free_stack(t_stack **stack);

// Utils Functions
void	handle_error(short exit_code);
void	clear_all(t_push *push_swap, short exit_code);
void	clear_invalid_command(t_push *push_swap, char *command);
void	free_split(char **split);

// Command Functions
void	read_commands(t_push *push_swap);
void	execute_commands(t_push *push_swap, char *command);
void	push(t_push *push_swap, t_cmd type, t_bool print_checker);
void	execute_push(t_stack **dst_stack, t_stack **src_stack);
void	swap(t_push *push_swap, t_cmd type, t_bool print_checker);
void	execute_swap(t_stack **stack);
void	rotate(t_push *push_swap, t_cmd type, t_bool print_checker);
void	execute_rotate(t_stack **stack);
void	reverse_rotate(t_push *push_swap, t_cmd type, t_bool print_checker);
void	execute_reverse_rotate(t_stack **stack);

#endif
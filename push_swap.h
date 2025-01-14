/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:16:23 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/08 15:09:43 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

int		is_zero_argument(char *arg);
int		is_numeric_argument(char *arg);
int		has_duplicate_arguments(char **argv);
int		get_stack_size(t_node *stack);
int		is_stack_sorted(t_node *stack);
int		ft_is_space(const char *str);
int		is_empty(char *str);
int		abs_value(int number);
int		ft_strcmps(const char *s1, const char *s2);
int		is_sign_character(char c);
int		is_valid_input(char **argv);
int		valid_int(char *str);
int		get_lowest_index_position(t_node **stack);
void	error_and_exit(t_node **stack_a, t_node **stack_b);
void	free_stack(t_node **stack);
void	execute_move(t_node **stack_a, t_node **stack_b, int cost_to_a,
			int cost_to_b);
void	cheapest_move(t_node **stack_a, t_node **stack_b);
void	reverse_rotation(t_node **stack);
void	execute_rotate(t_node **stack);
void	swap_a(t_node **stack_a);
void	push(t_node **stack_src, t_node **stack_dest);
void	rrb(t_node **stack_b);
void	rra(t_node **stack_a);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_stacks(t_node **stack_a, t_node **stack_b,
			int *cost_to_a, int *cost_to_b);
void	rotate_stacks(t_node **stack_a, t_node **stack_b, int *cost_to_a,
			int *cost_to_b);
void	rb(t_node **stack_b);
void	ra(t_node **stack_a);
void	sa(t_node **stack_a);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	rotate_stack_a(t_node **stack_a, int *cost);
void	rotate_stack_b(t_node **stack_b, int *cost);
void	add_node_to_bottom(t_node **stack, t_node *new_node);
void	push_swap(t_node **stack_a, t_node **stack_b, int stack_size);
void	sort_three_elements(t_node **stack);
void	sort_stack(t_node **stack_a, t_node **stack_b);
void	calculate_costs(t_node **stack_a, t_node **stack_b);
void	get_position_a(t_node **stack_a, t_node **stack_b);
void	shift_stack(t_node **stack_a);
void	check_parameters(int argc, char **argv, t_node **stack_a,
			t_node **stack_b);
void	check_str(char **argv, t_node **stack_a);
void	check_list_duplicates(t_node *stack_a);
void	do_rr(t_node **stack_a, t_node **stack_b);
void	do_rrr(t_node **stack_a, t_node **stack_b);
char	*get_next_line(int fd);
t_node	*create_new_node(int value);
t_node	*initialize_stack(int argc, char **argv);

#endif

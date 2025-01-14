/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:22:23 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/16 17:22:56 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_move(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strcmps(line, "sa\n") == 0)
		swap_a(stack_a);
	else if (ft_strcmps(line, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmps(line, "pb\n") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmps(line, "ra\n") == 0)
		execute_rotate(stack_a);
	else if (ft_strcmps(line, "rb\n") == 0)
		execute_rotate(stack_b);
	else if (ft_strcmps(line, "rr\n") == 0)
		do_rr(stack_a, stack_b);
	else if (ft_strcmps(line, "rra\n") == 0)
		reverse_rotation(stack_a);
	else if (ft_strcmps(line, "rrb\n") == 0)
		reverse_rotation(stack_b);
	else if (ft_strcmps(line, "rrr\n") == 0)
		do_rrr(stack_a, stack_b);
	else
		error_and_exit(stack_a, stack_b);
}

void	checker(t_node **stack_a, t_node **stack_b)
{
	char	*move;

	while (1)
	{
		move = get_next_line(0);
		if (move == NULL)
			break ;
		exec_move(stack_a, stack_b, move);
		free(move);
	}
	if (is_stack_sorted(*stack_a) == 1 && get_stack_size(*stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2 || is_empty(argv[1]))
		return (0);
	stack_b = NULL;
	if (argc == 2)
		check_str(argv, &stack_a);
	else
	{
		stack_a = initialize_stack(argc, argv);
		check_parameters(argc, argv, &stack_a, &stack_b);
	}
	checker(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

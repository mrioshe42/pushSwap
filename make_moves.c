/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:41 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/10 11:09:02 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stack(t_node **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void	cheapest_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*current_node;
	int		minimum_cost;
	int		cost_a;
	int		cost_b;

	current_node = *stack_b;
	minimum_cost = INT_MAX;
	while (current_node)
	{
		if (abs_value(current_node->cost_a) + abs_value(current_node->cost_b)
			< abs_value(minimum_cost))
		{
			minimum_cost = abs_value(current_node->cost_b)
				+ abs_value(current_node->cost_a);
			cost_a = current_node->cost_a;
			cost_b = current_node->cost_b;
		}
		current_node = current_node->next;
	}
	execute_move(stack_a, stack_b, cost_a, cost_b);
}

void	execute_move(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		reverse_rotate_stacks(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_stacks(stack_a, stack_b, &cost_a, &cost_b);
	rotate_stack_a(stack_a, &cost_a);
	rotate_stack_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:00:16 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/11 10:53:41 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_a;
	t_node	*node_b;
	int		size_a;
	int		size_b;

	node_a = *stack_a;
	node_b = *stack_b;
	size_a = get_stack_size(node_a);
	size_b = get_stack_size(node_b);
	while (node_b)
	{
		if (node_b->position <= size_b / 2)
			node_b->cost_b = node_b->position;
		else
			node_b->cost_b = (size_b - node_b->position) * -1;
		if (node_b->target_position <= size_a / 2)
			node_b->cost_a = node_b->target_position;
		else
			node_b->cost_a = (size_a - node_b->target_position) * -1;
		node_b = node_b->next;
	}
}

void	push_until_three(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;
	int	pushed;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	while (stack_size > 6 && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	while (get_stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	push_until_three(stack_a, stack_b);
	sort_three_elements(stack_a);
	while (*stack_b)
	{
		get_position_a(stack_a, stack_b);
		calculate_costs(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	while (!is_stack_sorted(*stack_a))
		shift_stack(stack_a);
}

void	sort_three_elements(t_node **stack)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = *stack;
	b = a->next;
	c = b->next;
	if (a->value > b->value && a->value > c->value)
		ra(stack);
	else if (b->value > a->value && b->value > c->value)
		rra(stack);
	a = *stack;
	b = a->next;
	if (a->value > b->value)
		sa(stack);
}

void	push_swap(t_node **stack_a, t_node **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_stack_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		sort_three_elements(stack_a);
	else if (stack_size > 3 && !is_stack_sorted(*stack_a))
		sort_stack(stack_a, stack_b);
}

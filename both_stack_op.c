/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_stack_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:19:19 by mrios-he          #+#    #+#             */
/*   Updated: 2024/06/03 16:40:34 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b)
{
	execute_rotate(stack_a);
	execute_rotate(stack_b);
	ft_printf("rr\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
	ft_printf("rrr\n");
}

void	reverse_rotate_stacks(t_node **stack_a, t_node **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(stack_a, stack_b);
	}
}

void	rotate_stacks(t_node **stack_a, t_node **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(stack_a, stack_b);
	}
}

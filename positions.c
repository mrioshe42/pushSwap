/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:22:06 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/11 16:22:33 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_node **stack_a, int index_b, int targ_index, int targ_pos)
{
	t_node	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index > index_b && temp_a->index < targ_index)
		{
			targ_index = temp_a->index;
			targ_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	if (targ_index != INT_MAX)
		return (targ_pos);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index < targ_index)
		{
			targ_index = temp_a->index;
			targ_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	return (targ_pos);
}

void	get_position(t_node **stack)
{
	t_node	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_lowest_index_position(t_node **stack)
{
	t_node	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	lowest_pos = tmp->position;
	get_position(stack);
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	get_position_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_b;
	int		targ_pos;

	temp_b = *stack_b;
	targ_pos = 0;
	get_position(stack_a);
	get_position(stack_b);
	while (temp_b)
	{
		temp_b->target_position = get_target(stack_a, temp_b->index,
				INT_MAX, targ_pos);
		temp_b = temp_b->next;
	}
}

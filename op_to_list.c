/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_to_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:40:43 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/11 10:56:33 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_and_exit(NULL, NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->position = 0;
	new_node->target_position = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_to_bottom(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

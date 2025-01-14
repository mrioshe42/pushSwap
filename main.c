/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:13:22 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/11 11:25:33 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_node *stack_a, int stack_size)
{
	t_node	*ptr;
	t_node	*highest_node;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest_node = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest_node = ptr;
				ptr = stack_a;
			}
			ptr = ptr->next;
		}
		if (highest_node != NULL)
			highest_node->index = stack_size;
	}
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
	if (is_stack_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	assign_indices(stack_a, get_stack_size(stack_a) + 1);
	push_swap(&stack_a, &stack_b, get_stack_size(stack_a));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

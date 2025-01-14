/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:59:21 by mrios-he          #+#    #+#             */
/*   Updated: 2024/06/11 15:01:22 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int_parameters(int argc, char **argv, t_node **stack_a,
	t_node **stack_b)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!valid_int(argv[i]))
			error_and_exit(stack_a, stack_b);
		i++;
	}
}

void	check_duplicates(int argc, char **argv, t_node **stack_a,
	t_node **stack_b)
{
	int		i;
	int		j;
	long	num1;
	long	num2;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		num1 = ft_atoi(argv[i]);
		while (j < argc)
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				error_and_exit(stack_a, stack_b);
			j++;
		}
		i++;
	}
}

void	check_list_duplicates(t_node *stack_a)
{
	t_node	*current;
	t_node	*checker;

	current = stack_a;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->value == checker->value)
				error_and_exit(&stack_a, NULL);
			checker = checker->next;
		}
		current = current->next;
	}
}

void	check_parameters(int argc, char **argv, t_node **stack_a,
	t_node **stack_b)
{
	check_int_parameters(argc, argv, stack_a, stack_b);
	check_duplicates(argc, argv, stack_a, stack_b);
}

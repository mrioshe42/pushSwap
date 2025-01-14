/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:02:53 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/11 11:06:18 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*initialize_stack(int argc, char **argv)
{
	t_node	*head;
	t_node	*current;
	t_node	*new_node;
	int		i;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			error_and_exit(&head, NULL);
		new_node->value = ft_atoi(argv[i]);
		new_node->next = NULL;
		if (!head)
			head = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	return (head);
}

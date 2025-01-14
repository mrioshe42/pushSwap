/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:51:15 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/17 14:52:13 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr(t_node **stack_a, t_node **stack_b)
{
	execute_rotate(stack_a);
	execute_rotate(stack_b);
}

void	do_rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
}

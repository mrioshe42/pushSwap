/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:02 by mrios-he          #+#    #+#             */
/*   Updated: 2024/06/11 15:38:24 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_int(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		num = num * 10 + (*str - '0');
		if (sign == 1 && num > INT_MAX)
			return (0);
		if (sign == -1 && (-num) < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

char	**tokenize_input(char *input)
{
	char	**tokens;

	tokens = ft_split(input, ' ');
	if (tokens == NULL)
		error_and_exit(NULL, NULL);
	return (tokens);
}

void	validate_and_create_list(char **tokens, t_node **head)
{
	t_node	*new_node;
	long	num;
	int		i;
	int		j;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (!valid_int(tokens[i]))
		{
			j = 0;
			while (tokens[j] != NULL)
			{
				free(tokens[j]);
				j++;
			}
			free(tokens);
			error_and_exit(head, NULL);
		}
		num = ft_atoi(tokens[i]);
		new_node = create_new_node(num);
		add_node_to_bottom(head, new_node);
		i++;
	}
}

void	str_to_list(char **argv, t_node **stack_a)
{
	char	**tokens;
	t_node	*head;
	int		i;

	head = NULL;
	i = 0;
	tokens = tokenize_input(argv[1]);
	validate_and_create_list(tokens, &head);
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	*stack_a = head;
}

void	check_str(char **argv, t_node **stack_a)
{
	if (argv[1] == NULL || argv[1][0] == '\0' || ft_is_space(argv[1]))
		error_and_exit(stack_a, NULL);
	str_to_list(argv, stack_a);
	check_list_duplicates(*stack_a);
}

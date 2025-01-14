/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:48:28 by mrios-he          #+#    #+#             */
/*   Updated: 2024/06/03 16:18:53 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(char *str)
{
	while (*str && *str == ' ')
		str++;
	if (!str)
		return (1);
	if (ft_strlen(str) == 0)
		return (1);
	return (0);
}

int	is_sign_character(char c)
{
	return (c == '+' || c == '-');
}

int	ft_strcmps(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	abs_value(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

int	ft_is_space(const char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 9 && *str <= 13) && *str != 32)
			return (0);
		str++;
	}
	return (1);
}

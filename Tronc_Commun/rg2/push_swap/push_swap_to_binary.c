/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_to_binary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:17:21 by lcompieg          #+#    #+#             */
/*   Updated: 2022/12/27 15:16:15 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nb_binary(int number)
{
	int	i;

	i = 0;
	while (number > 0)
	{
		number /= 2;
		i++;
	}
	return (i);
}

int	fd_idx(int value_to_find, t_stack *sorted_stack)
{
	int	i;

	i = 0;
	while (sorted_stack->value != value_to_find)
	{
		sorted_stack = sorted_stack->next;
		i++;
	}
	return (i);
}

char	*cvt_binary(int number)
{
	char	*binary_number;
	int		index;

	binary_number = malloc(sizeof(char) * (get_nb_binary(number) + 1));
	if (!binary_number)
		return (NULL);
	index = 0;
	if (number == 0)
	{
		binary_number[index] = '0';
		index++;
	}
	while (number > 0)
	{
		binary_number[index] = number % 2 + '0';
		number /= 2;
		index++;
	}
	binary_number[index] = '\0';
	return (binary_number);
}

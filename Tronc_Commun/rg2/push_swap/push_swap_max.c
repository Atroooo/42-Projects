/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_hardsort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:04:00 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/03 20:33:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_second_max(t_stack *stack_a)
{
	int	max;
	int	s_max;

	max = get_max_value(stack_a);
	s_max = get_min_value(stack_a);
	while (stack_a)
	{
		if (stack_a->value != max && stack_a->value > s_max)
			s_max = stack_a->value;
		stack_a = stack_a->next;
	}
	return (s_max);
}

int	get_min_value(t_stack *stack_a)
{
	int	min;

	min = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min)
			min = stack_a->value;
		stack_a = stack_a->next;
	}
	return (min);
}

int	get_max_value(t_stack *stack_a)
{
	int	max;

	max = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value > max)
			max = stack_a->value;
		stack_a = stack_a->next;
	}
	return (max);
}

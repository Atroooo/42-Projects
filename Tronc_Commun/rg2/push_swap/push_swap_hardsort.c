/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_hardsort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:04:00 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/10 14:12:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort_three_elem(t_stack **stack, char c)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = ((*stack)->next)->value;
	third = (((*stack)->next)->next)->value;
	if (stack_is_sort(*stack))
		return ;
	if (first > second && second > third)
		sort_action_one(stack, c);
	else if (first > second && first < third)
		ft_swap(stack, c);
	else if (first > second && second < third)
		ft_rotate(stack, c);
	else if (first < second && first > third)
		ft_rrotate(stack, c);
	else if (first < second && third < second)
		sort_action_two(stack, c);
}

static void	hard_sort_four_elem(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_is_sort(*stack_a))
		return ;
	while (ft_sizestack(*stack_b) != 2)
	{
		while ((*stack_a)->value != get_min_value(*stack_a))
			ft_rotate(stack_a, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	if ((*stack_a)->value > ((*stack_a)->next)->value)
		ft_swap(stack_a, 'a');
	if ((*stack_b)->value < ((*stack_b)->next)->value)
		ft_swap(stack_b, 'b');
	while (ft_sizestack(*stack_b) != 0)
		ft_push(stack_b, stack_a, 'a');
}

static void	hard_sort_five_elem(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	min = get_min_value(*stack_a);
	max = get_max_value(*stack_a);
	if (stack_is_sort(*stack_a))
		return ;
	while (ft_sizestack(*stack_b) < 2)
	{
		if ((*stack_a)->value == min || (*stack_a)->value == max)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, 'a');
	}
	hard_sort_three_elem(stack_a, 'a');
	if ((*stack_b)->value < ((*stack_b)->next)->value)
		ft_swap(stack_b, 'b');
	ft_push(stack_b, stack_a, 'a');
	ft_rotate(stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
}

void	hard_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	(void) stack_b;
	if (ft_sizestack(*stack_a) == 2)
	{
		if ((*stack_a)->value > ((*stack_a)->next)->value)
			ft_swap(stack_a, 'a');
	}
	else if (ft_sizestack(*stack_a) == 3)
		hard_sort_three_elem(stack_a, 'a');
	else if (ft_sizestack(*stack_a) == 4)
		hard_sort_four_elem(stack_a, stack_b);
	else if (ft_sizestack(*stack_a) == 5)
		hard_sort_five_elem(stack_a, stack_b);
}

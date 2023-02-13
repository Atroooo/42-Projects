/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:52:31 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/07 17:51:17 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fast_sort(t_stack *sorted_stack)
{
	t_stack	*temp_stack;
	int		temp;

	temp = 0;
	temp_stack = (sorted_stack)->next;
	while ((sorted_stack)->next)
	{
		while (temp_stack)
		{
			if ((sorted_stack)->value < temp_stack->value)
			{
				temp = (sorted_stack)->value;
				(sorted_stack)->value = temp_stack->value;
				temp_stack->value = temp;
			}
			temp_stack = temp_stack->next;
		}
		(sorted_stack) = (sorted_stack)->next;
		temp_stack = (sorted_stack);
	}
}

static void	sort_stack_radix(t_stack **stack_a, t_stack **stack_b, \
	t_stack **sorted_stack, int dgt_sort)
{
	int		index;
	char	*number;

	index = 0;
	if (stack_is_sort(*stack_a))
		return ;
	while (index < ft_sizestack(*sorted_stack))
	{
		number = cvt_binary(fd_idx((*stack_a)->value, *sorted_stack));
		if (ft_strlen(number) >= (size_t)dgt_sort)
		{
			if (number[dgt_sort] == '1')
				ft_push(stack_a, stack_b, 'b');
			else
				ft_rotate(stack_a, 'a');
		}
		else
			ft_rotate(stack_a, 'a');
		free(number);
		index++;
	}
	while (ft_sizestack(*stack_b) != 0)
		ft_push(stack_b, stack_a, 'a');
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_stack **sorted_stack)
{
	size_t		digit_sort;
	char		*nb_digit;

	if (ft_sizestack(*stack_a) <= 5)
		hard_sort_stack(stack_a, stack_b);
	else
	{
		fast_sort(*sorted_stack);
		digit_sort = 0;
		nb_digit = cvt_binary(fd_idx(\
			(ft_laststack(*sorted_stack, 0))->value, *sorted_stack));
		while (digit_sort < ft_strlen(nb_digit))
		{
			sort_stack_radix(stack_a, stack_b, sorted_stack, digit_sort);
			if (stack_is_sort(*stack_a))
				break ;
			digit_sort++;
		}
		free(nb_digit);
	}
}

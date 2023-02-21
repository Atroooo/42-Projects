/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:21:48 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/21 13:46:34 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_stack *stack, int s)
{
	if (s == 1)
		ft_putstr_fd("Error", 1);
	ft_clearstack(&stack);
	exit(1);
}

void	ft_clearstack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while ((*stack) != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int	check_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		while (stack->next)
		{
			stack = stack->next;
			if (temp->value == stack->value)
				return (0);
		}
		temp = temp->next;
		stack = temp;
	}
	return (1);
}

int	stack_is_sort(t_stack *stack)
{
	t_stack	*temp;

	temp = stack->next;
	while (stack->next)
	{
		if (stack->value > temp->value)
			return (0);
		stack = stack->next;
		temp = stack->next;
	}
	return (1);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

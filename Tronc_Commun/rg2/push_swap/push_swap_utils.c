/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:13:56 by lcompieg          #+#    #+#             */
/*   Updated: 2022/12/27 15:16:19 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->next = NULL;
	stack->value = value;
	return (stack);
}

t_stack	*ft_laststack(t_stack *stack, int sw)
{
	t_stack	*temp;

	if (stack == NULL)
		return (stack);
	else
	{
		if (sw == 0)
		{
			while (stack->next != NULL)
				stack = stack->next;
			return (stack);
		}
		else if (sw == 1)
		{
			while (stack->next != NULL)
			{
				temp = stack;
				stack = stack->next;
			}
			return (temp);
		}
	}
	return (stack);
}

void	ft_add_frontstack(t_stack **stack, t_stack *new)
{
	if ((*stack) == NULL)
	{
		*stack = new;
		return ;
	}
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void	ft_add_backstack(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
	{
		(*stack) = new;
		return ;
	}
	ft_laststack(*stack, 0)->next = new;
}

int	ft_sizestack(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

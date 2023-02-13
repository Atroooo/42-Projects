/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:50:15 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/03 19:47:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack		*next;
	int			temp;

	if (!stack || ft_sizestack(*stack) < 1)
		return ;
	next = (*stack)->next;
	temp = (*stack)->value;
	(*stack)->value = next->value;
	next->value = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_push(t_stack **stack_from, t_stack **stack_to, char c)
{
	t_stack	*temp;
	t_stack	*delete;

	if (!stack_from)
		return ;
	temp = ft_newstack((*stack_from)->value);
	ft_add_frontstack(stack_to, temp);
	delete = *stack_from;
	*stack_from = delete->next;
	free(delete);
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*next_elem;
	t_stack	*last;

	last = *stack;
	next_elem = (*stack)->next;
	if ((!*stack) || !(*stack)->next)
		return ;
	last = ft_laststack(last, 0);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = next_elem;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rrotate(t_stack **stack, char c)
{
	t_stack	*temp;
	t_stack	*delete;

	if (!stack)
		return ;
	temp = ft_newstack((*stack)->value);
	delete = *stack;
	*stack = delete->next;
	ft_add_backstack(stack, temp);
	free(delete);
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

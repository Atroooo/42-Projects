/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:32:22 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/09 14:52:43 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*temp_stack;

	if (argc == 1)
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	temp_stack = NULL;
	stack_a = fill_stack(stack_a, argv, argc);
	temp_stack = fill_stack(temp_stack, argv, argc);
	sort_stack(&stack_a, &stack_b, &temp_stack);
	ft_clearstack(&stack_a);
	ft_clearstack(&stack_b);
	ft_clearstack(&temp_stack);
	return (0);
}

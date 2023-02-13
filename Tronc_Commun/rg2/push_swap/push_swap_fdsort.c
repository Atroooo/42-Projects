/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fdsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:01:27 by lcompieg          #+#    #+#             */
/*   Updated: 2022/12/27 15:15:59 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_doubleswap(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, 'p');
	ft_swap(stack_b, 'p');
	write(1, "ss\n", 3);
}

void	ft_doublerotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 'p');
	ft_rotate(stack_b, 'p');
	write(1, "rr\n", 3);
}

void	ft_doublerrotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrotate(stack_a, 'a');
	ft_rrotate(stack_b, 'b');
	write(1, "rrr\n", 4);
}

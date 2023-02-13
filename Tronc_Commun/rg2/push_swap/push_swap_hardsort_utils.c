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

void	sort_action_one(t_stack **stack, char c)
{
	ft_rrotate(stack, c);
	ft_swap(stack, c);
	ft_rotate(stack, c);
}

void	sort_action_two(t_stack **stack, char c)
{
	ft_swap(stack, c);
	ft_rotate(stack, c);
}

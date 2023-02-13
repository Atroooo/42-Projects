/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:38:05 by lcompieg          #+#    #+#             */
/*   Updated: 2022/12/07 16:38:28 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_stack	*reverse_stack(t_stack *current)
// {
// 	t_stack	*previous;
// 	t_stack	*next;

// 	if (!current)
// 		return (NULL);
// 	previous = NULL;
// 	next = (current)->next;
// 	while ((current)->next != NULL)
// 	{
// 		(current)->next = previous;
// 		previous = current;
// 		(current) = next;
// 		next = next->next;
// 	}
// 	current->next = previous;
// 	return (current);
// }

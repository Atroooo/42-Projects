/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:46:23 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/03 18:42:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_number(long nb, int sign, t_stack *stack, char **str)
{
	if ((nb * sign) > -2147483648 && (nb * sign) < 2147483647)
		return (nb * sign);
	if ((nb * sign) < -2147483648)
	{
		if (str)
			free_split(str);
		print_error(stack, 1);
	}
	if ((nb * sign) > 2147483647)
	{
		if (str)
			free_split(str);
		print_error(stack, 1);
	}
	return (nb * sign);
}

static int	check_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi_s(const char *str, t_stack *stack, char **split)
{
	int			sign;
	long int	nb;
	int			index;

	sign = 1;
	nb = 0;
	index = 0;
	while (check_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (48 <= str[index] && str[index] <= 57)
	{
		nb = (nb * 10) + str[index] - '0';
		if (str[index + 1] == '\0')
			return (return_number(nb, sign, stack, split));
		if (!(48 <= str[index + 1] && str[index + 1] <= 57))
			print_error(stack, 1);
		index++;
	}
	return (0);
}

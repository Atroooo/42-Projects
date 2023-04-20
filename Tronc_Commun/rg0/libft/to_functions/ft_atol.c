/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:36:30 by lcompieg          #+#    #+#             */
/*   Updated: 2023/04/19 16:37:03 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static long long	return_number(double long nb, int sign)
{
	if ((nb * sign) > LLONG_MIN && (nb * sign) < LLONG_MAX)
		return (nb * sign);
	if ((nb * sign) < LLONG_MIN)
		return (-1);
	if ((nb * sign) > LLONG_MAX)
		return (-1);
	return (nb * sign);
}

long long	ft_atol(const char *str)
{
	int			sign;
	double long	nb;
	int			i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (48 <= str[i] && str[i] <= 57)
	{
		nb = (nb * 10) + str[i] - '0';
		if (!(48 <= str[i + 1] && str[i + 1] <= 57))
			return (return_number(nb, sign));
		i++;
	}
	return (0);
}

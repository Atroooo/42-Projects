/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:52:56 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/17 20:07:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	return_number(long nb, int sign)
{
	if ((nb * sign) > -2147483648 && (nb * sign) < 2147483647)
		return (nb * sign);
	if ((nb * sign) < -2147483648)
		return (0);
	if ((nb * sign) > 2147483647)
		return (-1);
	return (nb * sign);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long int	nb;
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

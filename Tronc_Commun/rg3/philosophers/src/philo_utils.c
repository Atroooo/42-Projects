/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:51 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 16:49:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp_philo(t_philo *philo)
{
	long long	time;

	gettimeofday(&philo->tv, NULL);
	time = 1000000 * philo->tv.tv_sec + philo->tv.tv_usec;
	time = (time - philo->start) * 0.001;
	return (time);
}

void	print_msg(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->stop_cond == 0)
		printf("%lld %d%s", timestamp_philo(philo), philo->pos, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_usleep(long long time, t_philo *philo)
{
	long long	start;

	start = timestamp_philo(philo);
	while (timestamp_philo(philo) - start < time)
		usleep(100);
}

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

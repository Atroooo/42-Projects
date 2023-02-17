/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rountine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:32:12 by marvin            #+#    #+#             */
/*   Updated: 2023/02/15 21:32:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	take_fork(t_philo *philo)
{
	(void) philo;
	return ;
}

void	philo_eat(t_philo *philo)
{
	(void) philo;
	return ;
}

void	philo_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->stop);
	print(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	pthread_mutex_unlock(&philo->stop);
	pthread_mutex_lock(&philo->stop);
	print(philo, "is thinking");
	pthread_mutex_unlock(&philo->stop);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->stop);
	if (philo->last_eat - philo->data->time_to_die < 0)
	{
		pthread_mutex_unlock(&philo->stop);
		return (1);
	}
	if (philo->data->nb_eat > 0 && \
		philo->m_eat == philo->data->nb_eat)
	{
		pthread_mutex_unlock(&philo->stop);
		return (2);
	}
	pthread_mutex_unlock(&philo->stop);
	return (0);
}

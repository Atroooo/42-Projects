/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:10:26 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/26 23:42:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	set_dead(t_env *env, int s)
{
	int	index;

	index = 0;
	while (index < env->nb_philo)
	{
		if (env->philo[index].fork.__data.__lock == 1)
			pthread_mutex_unlock(&env->philo[index].fork);
		pthread_mutex_lock(&env->philo[index].death);
		if (s == 0)
			env->philo[index].dead = 1;
		if (s == 1)
			env->philo[index].dead = 2;
		index++;
	}
}

int	check_dead(t_env *env)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < env->nb_philo)
	{
		if (env->philo[index].dead == 1)
		{
			set_dead(env, 0);
			return (1);
		}
		if (env->philo[index].dead == 2)
			count++;
		index++;
	}
	if (count == env->nb_philo)
	{
		set_dead(env, 1);
		return (1);
	}
	return (0);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->stop);
	if ((timestamp() - philo->last_eat) < philo->data->time_to_die)
	{
		philo->dead = 1;
		pthread_mutex_unlock(&philo->stop);
		return (1);
	}
	if (philo->data->nb_eat > 0 && \
		philo->m_eat == philo->data->nb_eat)
	{
		philo->dead = 2;
		pthread_mutex_unlock(&philo->stop);
		return (2);
	}
	pthread_mutex_unlock(&philo->stop);
	return (0);
}

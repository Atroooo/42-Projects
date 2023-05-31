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

#include "philo.h"

void	philo_eat_sleep_think(t_philo *philo)
{
	print_msg(" is eating\n", philo);
	pthread_mutex_lock(&philo->stop);
	philo->last_eat = timestamp_philo(philo);
	philo->m_eat++;
	pthread_mutex_unlock(&philo->stop);
	ft_usleep(philo->data->time_to_eat, philo);
	depose_fork(philo, philo->next_philo);
	print_msg(" is sleeping\n", philo);
	ft_usleep(philo->data->time_to_sleep, philo);
	print_msg(" is thinking\n", philo);
	usleep(100);
}

static int	end_meal(t_philo *philo, t_env *env)
{
	pthread_mutex_lock(&env->print);
	philo->data->stop_cond = 1;
	pthread_mutex_unlock(&env->print);
	if (philo->stop.__data.__lock == 1)
		pthread_mutex_unlock(&philo->stop);
	return (1);
}

static void	change_stop_cond(t_env *env)
{
	pthread_mutex_lock(&env->print);
	env->stop_cond = 1;
	pthread_mutex_unlock(&env->print);
}

int	check_dead(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nb_philo)
	{
		pthread_mutex_lock(&env->philo[i].stop);
		if ((tmstmp_env(env) - env->philo[i].last_eat) > env->time_to_die)
		{
			change_stop_cond(env);
			printf("%lld %d is dead\n", tmstmp_env(env), (env->philo + i)->pos);
			pthread_mutex_unlock(&env->philo[i].stop);
			return (1);
		}
		if (env->nb_eat > 0 && env->philo[i].m_eat == env->nb_eat)
		{
			env->philo[i].m_eat++;
			env->count++;
			if (env->count == env->nb_philo)
				return (end_meal(&env->philo[i], env));
		}
		if (env->philo[i].stop.__data.__lock == 1)
			pthread_mutex_unlock(&env->philo[i].stop);
	}
	return (0);
}

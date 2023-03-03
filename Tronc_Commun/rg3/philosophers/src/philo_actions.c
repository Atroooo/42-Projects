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

void	philo_sleep_think(t_philo *philo)
{
	print_msg(" is sleeping\n", philo);
	usleep(philo->data->time_to_sleep * 1000);
	philo->think = 1;
	print_msg(" is thinking\n", philo);
}

void	philo_eat(t_philo *philo)
{
	print_msg(" is eating\n", philo);
	pthread_mutex_lock(&philo->stop);
	philo->last_eat = timestamp(philo->data);
	philo->m_eat++;
	pthread_mutex_unlock(&philo->stop);
	philo->think = 0;
	usleep(philo->data->time_to_eat * 1000);
	depose_fork(philo, philo->next_philo);
}

static int	end_meal(t_philo *philo)
{
	philo->data->stop_cond = 1;
	pthread_mutex_unlock(&philo->death);
	return (1);
}

int	check_dead(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nb_philo)
	{
		pthread_mutex_lock(&env->philo[i].death);
		if ((timestamp(env) - env->philo[i].last_eat) >= env->time_to_die)
		{
			env->stop_cond = 1;
			printf("%lld %d is dead\n", timestamp(env), (env->philo + i)->pos);
			pthread_mutex_unlock(&env->philo[i].death);
			return (1);
		}
		if (env->nb_eat > 0 && env->philo[i].m_eat == env->nb_eat)
		{
			env->philo[i].m_eat++;
			env->count++;
			if (env->count == env->nb_philo)
				return (end_meal(&env->philo[i]));
		}
		pthread_mutex_unlock(&env->philo[i].death);
	}
	return (0);
}

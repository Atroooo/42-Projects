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

int	take_fork(t_philo *philo)
{
	t_philo	*next_philo;

	if (philo->pos == philo->data->nb_philo)
		next_philo = philo - (philo->pos - 1);
	else if (philo + 1)
		next_philo = philo + 1;
	if (lock_fork(philo, next_philo))
		return (print_msg(" has taken a fork\n", philo), 1);
	return (0);
}

void	philo_sleep_think(t_philo *philo)
{
	print_msg(" is sleeping\n", philo);
	usleep(philo->data->time_to_sleep * 1000);
	philo->think = 1;
	print_msg(" is thinking\n", philo);
}

static void	depose_fork(t_philo *philo)
{
	t_philo	*next_philo;

	if (philo->pos == philo->data->nb_philo)
		next_philo = philo - (philo->pos - 1);
	else
		next_philo = philo + 1;
	unlock_fork(philo, next_philo);
}

void	philo_eat(t_philo *philo)
{
	print_msg(" is eating\n", philo);
	pthread_mutex_lock(&philo->stop);
	philo->last_eat = timestamp(philo->data) + philo->data->time_to_eat;
	philo->m_eat++;
	pthread_mutex_unlock(&philo->stop);
	usleep(philo->data->time_to_eat * 1000);
	depose_fork(philo);
	philo->think = 0;
	return ;
}

int	check_dead(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_mutex_lock(&env->death);
		// printf("pos %d ts %lld\n", env->philo[i].pos, (timestamp(env) - env->philo[i].last_eat));
		if ((timestamp(env) - env->philo[i].last_eat) >= env->time_to_die)
		{
			env->stop_cond = 1;
			printf("%lld %d is dead\n", timestamp(env), \
				(env->philo + i)->pos);
			pthread_mutex_unlock(&env->death);
			return (1);
		}
		if (env->nb_eat > 0 && env->philo[i].m_eat == env->nb_eat)
		{
			env->stop_cond = 1;
			pthread_mutex_unlock(&env->death);
			return (1);
		}
		pthread_mutex_unlock(&env->death);
		i++;
	}
	return (0);
}

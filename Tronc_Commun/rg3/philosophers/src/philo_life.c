/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:53 by lcompieg          #+#    #+#             */
/*   Updated: 2023/03/09 21:38:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	stop_cond(t_philo *philo)
{
	pthread_mutex_lock(&philo->stop);
	if (philo->data->stop_cond == 0)
	{
		pthread_mutex_unlock(&philo->stop);
		return (1);
	}
	pthread_mutex_unlock(&philo->stop);
	return (0);
}

static void	*routine(void *phil)
{
	t_philo		*philo;

	philo = (t_philo *) phil;
	if (philo->pos == philo->data->nb_philo)
		philo->next_philo = philo - (philo->pos - 1);
	else
		philo->next_philo = philo + 1;
	while (stop_cond(philo))
	{
		take_fork(philo);
		philo_eat_sleep_think(philo);
	}
	return (NULL);
}

static int	create_thread(t_env *env)
{
	int	index;

	index = 0;
	while (index < env->nb_philo)
	{
		if (pthread_create(&env->philo[index].th, NULL, \
			&routine, &env->philo[index]) != 0)
			return (0);
		usleep(200);
		index++;
	}
	return (1);
}

int	philo_life(t_env *env)
{
	int	index;

	if (!create_thread(env))
		return (0);
	while (1)
	{
		if (check_dead(env))
			break ;
		usleep(100);
	}
	index = 0;
	while (index < env->nb_philo)
	{
		if (pthread_join(env->philo[index].th, NULL) != 0)
			return (0);
		index++;
	}
	return (1);
}

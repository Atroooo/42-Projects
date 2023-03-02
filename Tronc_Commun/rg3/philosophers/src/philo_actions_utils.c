/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:01:41 by lcompieg          #+#    #+#             */
/*   Updated: 2023/03/02 13:52:22 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	lock_mutex(t_philo *philo, t_philo *next_philo, int s)
{
	if (s == 1)
	{
		pthread_mutex_lock(&next_philo->fork);
		pthread_mutex_lock(&philo->fork);
	}
	if (s == 2)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&next_philo->fork);
	}
}

int	lock_fork(t_philo *philo, t_philo *next_philo)
{
	if (!philo || !next_philo)
		return (0);
	pthread_mutex_lock(&philo->stop);
	if (philo->f_taken == 0 && next_philo->f_taken == 0)
	{
		pthread_mutex_unlock(&philo->stop);
		if (philo->pos == philo->data->nb_philo)
			lock_mutex(philo, next_philo, 1);
		else
			lock_mutex(philo, next_philo, 2);
		philo->f_taken = 1;
		next_philo->f_taken = 1;
		return (1);
	}
	pthread_mutex_unlock(&philo->stop);
	return (0);
}

void	depose_fork(t_philo *philo)
{
	t_philo	*next_philo;

	if (philo->pos == philo->data->nb_philo)
		next_philo = philo - (philo->pos - 1);
	else
		next_philo = philo + 1;
	unlock_fork(philo, next_philo);
}

void	unlock_fork(t_philo *philo, t_philo *next_philo)
{
	if (!philo || !next_philo)
		return ;
	philo->f_taken = 0;
	next_philo->f_taken = 0;
	if (philo->fork.__data.__lock == 1)
		pthread_mutex_unlock(&philo->fork);
	if (next_philo->fork.__data.__lock == 1)
		pthread_mutex_unlock(&next_philo->fork);
}

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

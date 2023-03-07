/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:01:41 by lcompieg          #+#    #+#             */
/*   Updated: 2023/03/07 11:35:23 by marvin           ###   ########.fr       */
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

void	depose_fork(t_philo *philo, t_philo *next_philo)
{
	if (!philo || !next_philo)
		return ;
	philo->f_taken = 0;
	next_philo->f_taken = 0;
	if (next_philo->fork.__data.__lock == 1)
		pthread_mutex_unlock(&next_philo->fork);
	if (philo->fork.__data.__lock == 1)
		pthread_mutex_unlock(&philo->fork);
}

void	take_fork(t_philo *philo)
{
	if (!philo || !philo->next_philo)
		return ;
	// pthread_mutex_lock(&philo->stop);
	// if (philo->f_taken == 0 && philo->next_philo->f_taken == 0)
	// {
	// 	if (philo->stop.__data.__lock == 1)
	// 		pthread_mutex_unlock(&philo->stop);
		if (philo->pos == philo->data->nb_philo)
			lock_mutex(philo, philo->next_philo, 1);
		else
			lock_mutex(philo, philo->next_philo, 2);
		philo->f_taken = 1;
		philo->next_philo->f_taken = 1;
		print_msg(" has taken a fork\n", philo);
	// }
	// if (philo->stop.__data.__lock == 1)
	// 	pthread_mutex_unlock(&philo->stop);
}

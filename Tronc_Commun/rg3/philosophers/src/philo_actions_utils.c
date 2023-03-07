/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:01:41 by lcompieg          #+#    #+#             */
/*   Updated: 2023/03/07 13:42:06 by lcompieg         ###   ########.fr       */
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
	pthread_mutex_unlock(&next_philo->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	take_fork(t_philo *philo)
{
	if (!philo || !philo->next_philo)
		return ;
	if (philo->pos == philo->data->nb_philo)
		lock_mutex(philo, philo->next_philo, 1);
	else
		lock_mutex(philo, philo->next_philo, 2);
	philo->f_taken = 1;
	philo->next_philo->f_taken = 1;
	print_msg(" has taken a fork\n", philo);
	print_msg(" has taken a fork\n", philo);
}

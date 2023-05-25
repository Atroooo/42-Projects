/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:01:41 by lcompieg          #+#    #+#             */
/*   Updated: 2023/05/25 12:46:10 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	lock_mutex(t_philo *philo, t_philo *next_philo, int s)
{
	if (s == 1)
	{
		pthread_mutex_lock(&next_philo->fork);
		print_msg(" has taken a fork\n", philo);
		pthread_mutex_lock(&philo->fork);
		print_msg(" has taken a fork\n", philo);
	}
	if (s == 2)
	{
		pthread_mutex_lock(&philo->fork);
		print_msg(" has taken a fork\n", philo);
		pthread_mutex_lock(&next_philo->fork);
		print_msg(" has taken a fork\n", philo);
	}
}

void	depose_fork(t_philo *philo, t_philo *next_philo)
{
	if (!philo || !next_philo)
		return ;
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
}

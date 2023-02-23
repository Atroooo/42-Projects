/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:01:41 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/23 16:05:37 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	take_fork_s(t_philo *philo)
{
	if (philo->pos - 1 == 0)
	{
		if ((philo + 1)->f_taken == 0 && (philo + 1)->fork.__data.__lock == 0)
			lock_fork(philo, philo + 1, 0);
		else if ((philo + (philo->data->nb_philo - 1))->f_taken == 0 && \
			(philo + (philo->data->nb_philo - 1))->fork.__data.__lock == 0)
			lock_fork(philo, (philo + (philo->data->nb_philo - 1)), 0);
		return ;
	}
	else if (philo->pos == philo->data->nb_philo)
	{
		if ((philo - 1)->f_taken == 0 && (philo - 1)->fork.__data.__lock == 0)
			lock_fork(philo, (philo - 1), 1);
		else if ((philo - (philo->pos - 1))->f_taken == 0 && \
			(philo - (philo->pos - 1))->fork.__data.__lock == 0)
			lock_fork(philo, (philo - (philo->pos - 1)), 1);
		return ;
	}
}

void	lock_fork(t_philo *philo, t_philo *next_philo, int s)
{
	if ((next_philo)->fork.__data.__lock == 0)
		pthread_mutex_lock(&(next_philo)->fork);
	if (s == 0)
	{
		philo->r_taken = 1;
		philo->f_taken = 1;
		next_philo->f_taken = 1;
	}
	else if (s == 1)
	{
		philo->l_taken = 1;
		philo->f_taken = 1;
		next_philo->f_taken = 1;
	}
}

void	unlock_fork(t_philo *philo, t_philo *next_philo, int s)
{
	if (s == 0)
	{
		philo->r_taken = 0;
		philo->f_taken = 0;
		next_philo->f_taken = 0;
	}
	else if (s == 1)
	{
		philo->l_taken = 0;
		philo->f_taken = 0;
		next_philo->f_taken = 0;
	}
	if ((next_philo)->fork.__data.__lock == 1)
		pthread_mutex_unlock(&(next_philo)->fork);
}

void	eat_left(t_philo *philo)
{
	if (philo->pos - 1 == 0)
		unlock_fork(philo, philo + philo->data->nb_philo - 1, 1);
	else
		unlock_fork(philo, philo - 1, 1);
}

void	eat_right(t_philo *philo)
{
	if (philo->pos == philo->data->nb_philo)
		unlock_fork(philo, philo - (philo->pos - 1), 0);
	else
		unlock_fork(philo, philo + 1, 0);
}

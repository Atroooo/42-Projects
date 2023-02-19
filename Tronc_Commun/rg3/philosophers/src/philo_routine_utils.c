/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:01:41 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/19 13:13:36 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	lock_fork(t_philo *philo, t_philo *next_philo, int s)
{
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

void	take_fork_s(t_philo *philo)
{
	if (philo->pos - 1 == 0)
	{
		pthread_mutex_lock(&(philo + (philo->data->nb_philo - 1))->fork);
		lock_fork(philo, (philo + (philo->data->nb_philo - 1)), 0);
		return ;
	}
	else if (philo->pos == philo->data->nb_philo)
	{
		pthread_mutex_lock(&(philo - (philo->pos - 1))->fork);
		lock_fork(philo, (philo - (philo->pos - 1)), 1);
		return ;
	}
}

void	eat_left(t_philo *philo)
{
	if (philo->pos - 1 == 0)
	{
		(philo + (philo->data->nb_philo - 1))->f_taken = 0;
		pthread_mutex_unlock(&(philo + (philo->data->nb_philo - 1))->fork);
	}
	else
	{
		(philo - 1)->f_taken = 0;
		pthread_mutex_unlock(&(philo - 1)->fork);
	}
	philo->l_taken = 0;
}

void	eat_right(t_philo *philo)
{
	if (philo->pos == philo->data->nb_philo)
	{
		(philo - (philo->pos - 1))->f_taken = 0;
		pthread_mutex_unlock(&(philo - (philo->pos - 1))->fork);
	}
	else
	{
		(philo + 1)->f_taken = 0;
		pthread_mutex_unlock(&(philo + 1)->fork);
	}	
	philo->r_taken = 0;
}

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

static void	take_fork_s(t_philo *philo)
{
	if (philo->pos - 1 == 0)
	{
		pthread_mutex_lock(&(philo + (philo->data->nb_philo - 1))->fork);
		(philo + (philo->data->nb_philo - 1))->f_taken = 1;
		philo->r_taken = 1;
		return ;
	}
	else if (philo->pos == philo->data->nb_philo)
	{
		pthread_mutex_lock(&(philo - (philo->pos - 1))->fork);
		(philo - (philo->pos - 1))->f_taken = 1;
		philo->l_taken = 1;
		return ;
	}
}

int	take_fork(t_philo *philo, long long start)
{
	if (philo->f_taken == 0)
	{
		pthread_mutex_lock(&philo->fork);
		philo->f_taken = 1;
		if ((philo->pos - 1 == 0) || (philo->pos == philo->data->nb_philo))
		{
			take_fork_s(philo);
			printf("%lld %d has taken a fork", timestamp() - start, philo->pos);
			return (1);
		}
		if ((philo + 1) && (philo + 1)->f_taken == 0)
		{
			pthread_mutex_lock(&(philo + 1)->fork);
			(philo + 1)->f_taken = 1;
			philo->r_taken = 1;
			printf("%lld %d has taken a fork", timestamp() - start, philo->pos);
			return (1);
		}
		else if ((philo - 1) && (philo - 1)->f_taken == 0)
		{
			pthread_mutex_lock(&(philo - 1)->fork);
			(philo - 1)->f_taken = 1;
			philo->l_taken = 1;
			printf("%lld %d has taken a fork", timestamp() - start, philo->pos);
			return (1);
		}
	}
	return (0);
}

void	philo_eat(t_philo *philo, long long start)
{
	pthread_mutex_lock(&philo->stop);
	printf("%lld %d is eating", timestamp() - start, philo->pos);
	ft_usleep(philo->data->time_to_eat);
	philo->f_taken = 0;
	if (philo->r_taken == 1) //cas ou c est pos = 0 ou pos = dernier
	{
		philo->r_taken = 0;
		pthread_mutex_unlock(&(philo + 1)->fork);
	}
	else if (philo->l_taken == 1)
	{
		philo->l_taken  = 0;
		pthread_mutex_unlock(&(philo - 1)->fork);
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->stop);
	return ;
}
//Temps que le philo n a pas mange il est dans l etat penser donc juste mettre un SWITCH
void	philo_sleep_think(t_philo *philo, long long start)
{
	pthread_mutex_lock(&philo->stop);
	printf("%lld %d is sleeping.\n", timestamp() - start, philo->pos);
	ft_usleep(philo->data->time_to_sleep);
	pthread_mutex_unlock(&philo->stop);
	pthread_mutex_lock(&philo->stop);
	printf("%lld %d is thinking.\n", timestamp() - start, philo->pos);
	pthread_mutex_unlock(&philo->stop);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->stop);
	if (philo->last_eat - philo->data->time_to_die < 0)
	{
		philo->dead = 1;
		pthread_mutex_unlock(&philo->stop);
		return (1);
	}
	if (philo->data->nb_eat > 0 && \
		philo->m_eat == philo->data->nb_eat)
	{
		philo->dead = 2;
		pthread_mutex_unlock(&philo->stop);
		return (2);
	}
	pthread_mutex_unlock(&philo->stop);
	return (0);
}

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

int	take_fork(t_philo *philo, long long st)
{
	if (philo->f_taken == 0)
	{
		if ((philo->pos - 1 == 0) || (philo->pos == philo->data->nb_philo))
		{
			take_fork_s(philo);
			printf("%lld %d has taken a fork\n", timestamp() - st, philo->pos);
			return (1);
		}
		else if ((philo + 1) && (philo + 1)->f_taken == 0 && (philo + 1)->fork.__data.__lock == 0)
		{
			lock_fork(philo, philo + 1, 0);
			printf("%lld %d has taken a fork\n", timestamp() - st, philo->pos);
			return (1);
		}
		else if ((philo - 1) && (philo - 1)->f_taken == 0 && (philo - 1)->fork.__data.__lock == 0)
		{
			lock_fork(philo, philo - 1, 1);
			printf("%lld %d has taken a fork\n", timestamp() - st, philo->pos);
			return (1);
		}
	}
	return (0);
}

void	philo_eat(t_philo *philo, long long start)
{
	printf("%lld %d is eating\n", timestamp() - start, philo->pos);
	ft_usleep(philo->data->time_to_eat);
	philo->f_taken = 0;
	if (philo->r_taken == 1)
		eat_right(philo);
	else if (philo->l_taken == 1)
		eat_left(philo);
	philo->last_eat = timestamp();
	philo->think = 0;
	return ;
}

void	philo_sleep_think(t_philo *philo, long long start)
{
	printf("%lld %d is sleeping.\n", timestamp() - start, philo->pos);
	ft_usleep(philo->data->time_to_sleep);
	philo->think = 1;
	printf("%lld %d is thinking.\n", timestamp() - start, philo->pos);
}

int	is_dead(t_philo *philo)
{
	if ((timestamp() - philo->last_eat) < philo->data->time_to_die)
	{
		philo->dead = 1;
		return (1);
	}
	if (philo->data->nb_eat > 0 && \
		philo->m_eat == philo->data->nb_eat)
	{
		philo->dead = 2;
		return (2);
	}
	return (0);
}

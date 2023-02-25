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
	t_philo *next_philo;

	if (philo->pos == philo->data->nb_philo)
		next_philo = philo - (philo->pos - 1);
	else if (philo + 1)
		next_philo = philo + 1;
	if (lock_fork(philo, next_philo))
		return (print_msg(" has taken a fork\n", st, philo), 1);
	return (0);
}

void	philo_sleep_think(t_philo *philo, long long start)
{
	print_msg(" is sleeping\n", start, philo);
	ft_usleep(philo->data->time_to_sleep);
	philo->think = 1;
	print_msg(" is thinking\n", start, philo);
}

static void	depose_fork(t_philo *philo)
{
	t_philo *next_philo;

	if (philo->pos == philo->data->nb_philo)
		next_philo = philo - (philo->pos - 1);
	else
		next_philo = philo + 1;
	unlock_fork(philo, next_philo);
}

void	philo_eat(t_philo *philo, long long st)
{
	print_msg(" is eating\n", st, philo);
	ft_usleep(philo->data->time_to_eat);
	depose_fork(philo);
	philo->last_eat = timestamp();
	philo->think = 0;
	return ;
}

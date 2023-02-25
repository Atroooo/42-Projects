/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:53 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/25 17:54:25 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	*routine(void *phil)
{
	t_philo		*philo;
	long long	start;

	philo = (t_philo *) phil;
	start = timestamp();
	while (!is_dead(philo) && philo->dead == 0)
	{
		if (take_fork(philo, start))
			philo_eat(philo, start);
		if (philo->think == 0)
			philo_sleep_think(philo, start);
	}
	if (is_dead(philo) == 1 && philo->dead == 1)
	{
		print_msg(" is dead.\n", start, philo);
		return (NULL);
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
		usleep(100);
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
		usleep(50);
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

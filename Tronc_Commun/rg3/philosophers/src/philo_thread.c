/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:53 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/22 17:40:20 by lcompieg         ###   ########.fr       */
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
		printf("%lld %d is dead.\n", timestamp() - start, philo->pos);
		return (NULL);
	}
	return (NULL);
}

static int	init_var(t_philo *philo, int index)
{
	philo->pos = index + 1;
	philo->m_eat = 0;
	philo->last_eat = 0;
	philo->dead = 0;
	philo->r_taken = 0;
	philo->l_taken = 0;
	philo->think = 1;
	if (pthread_mutex_init(&philo->fork, NULL) != 0)
		return (0);
	philo->f_taken = 0;
	return (1);
}

static int	create_philo(t_env *env)
{
	int	index;

	index = 0;
	env->philo = malloc(sizeof(t_philo) * env->nb_philo);
	if (!env->philo)
		return (0);
	while (index < env->nb_philo)
	{
		env->philo[index].data = env;
		if (!init_var(&env->philo[index], index))
			return (0);
		if (pthread_create(&env->philo[index].th, NULL, \
			&routine, &env->philo[index]) != 0)
			return (0);
		index++;
	}
	return (1);
}

int	philo_life(t_env *env)
{
	int	index;

	if (pthread_mutex_init(&env->death, NULL) != 0)
		return (0);
	if (!create_philo(env))
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

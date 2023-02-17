/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:53 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/17 21:01:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	*routine(void *philo)
{
	while (!is_dead(philo))
	{
		take_fork(philo);
		philo_eat(philo);
		philo_sleep_think(philo);
	}
	if (is_dead(philo) == 1)
	{
		print(philo, "is dead.");
		return (NULL);
	}
	return (NULL);
}

static void	init_var(t_philo *philo, int index)
{
	philo->pos = index + 1;
	philo->m_eat = 0;
	philo->last_eat = 0;
	if (pthread_mutex_init(&philo->fork_l, NULL) != 0)
		return ;
	philo->l_taken = 0;
	if (pthread_mutex_init(&philo->fork_r, NULL) != 0)
		return ;
	philo->r_taken = 0;
	if (pthread_mutex_init(&philo->stop, NULL) != 0)
		return ;
}

void	create_philo(t_env *env)
{
	int	index;

	index = 0;
	env->philo = malloc(sizeof(t_philo *) * env->nb_philo);
	if (!env->philo)
		return ;
	while (index < env->nb_philo)
	{
		env->philo[index] = malloc(sizeof(t_philo));
		if (!env->philo[index])
			return ;
		env->philo[index]->data = env;
		init_var(env->philo[index], index);
		if (pthread_create(&env->philo[index]->th, NULL, \
			&routine, &env->philo[index]) != 0)
			return ;
		index++;
	}
	index = 0;
	while (index < env->nb_philo)
	{
		if (pthread_join(env->philo[index]->th, NULL) != 0)
			return ;
		index++;
	}
}

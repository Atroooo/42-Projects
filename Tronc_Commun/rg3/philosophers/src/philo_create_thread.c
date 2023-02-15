/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:53 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/15 14:24:15 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	*routine(void *arg)
{
	(void) arg;
	return (NULL);
}

static void	init_var(t_philo *philo, int index)
{
	philo->dead = 0;
    philo->pos = index + 1;
}

void	create_philo(t_env *env)
{
	int	index;

	index = 0;
	env->philo = malloc(sizeof(t_philo *) * env->nb_philo);
	while (index < env->nb_philo)
	{
		env->philo[index] = malloc(sizeof(t_philo));
		init_var(env->philo[index], index);
		if (pthread_create(&env->philo[index]->th, NULL, &routine, &index) != 0)
			return ;
		pthread_mutex_init(&env->philo[index]->fork, NULL);
		index++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:53 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/15 22:13:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	init_var(t_philo *philo, int index)
{
	philo->dead = 0;
    philo->pos = index + 1;
	philo->nb_eat = 0;
	philo->last_eat = 0;
}

void	create_philo(t_env *env)
{
	int	index;

	index = 0;
	env->philo = malloc(sizeof(t_philo *) * env->nb_philo);
	while (index < env->nb_philo)
	{
		env->philo[index] = malloc(sizeof(t_philo));
		if (pthread_create(&env->philo[index]->th, NULL, &routine, &env->philo[index]) != 0)
			return ;
		pthread_mutex_init(&env->philo[index]->fork_l, NULL);
		pthread_mutex_init(&env->philo[index]->fork_r, NULL);
		index++;
	}
}

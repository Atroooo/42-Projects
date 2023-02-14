/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:53 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/14 20:35:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	*routine(void *arg)
{
	(void) arg;
	return (NULL);
}

void	create_philo(t_env *env)
{
	int	index;

	index = 0;
	env->philo = malloc(sizeof(t_philo *) * env->nb_philo);
	while (index < env->nb_philo)
	{
		env->philo[index] = malloc(sizeof(t_philo));
        env->philo[index]->pos = index + 1;
		if (pthread_create(&env->philo[index]->thread, NULL, &routine, &index) != 0)
			return ;
		if (pthread_join(env->philo[index]->thread, NULL) != 0)
			return ;	
		pthread_mutex_init(&env->philo[index]->mutex, NULL);
		index++;
	}
}

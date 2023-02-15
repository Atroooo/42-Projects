/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:36:48 by marvin            #+#    #+#             */
/*   Updated: 2023/02/14 20:36:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	free_env(t_env *env)
{
	int	index;

	index = 0;
	while (index < env->nb_philo)
	{
		if (env->philo[index]->th)
			pthread_detach(env->philo[index]->th);
		if (pthread_mutex_destroy(&env->philo[index]->fork))
			pthread_mutex_destroy(&env->philo[index]->fork);
		if (env->philo[index])
		free(env->philo[index]);
	}
	if (env->philo)
		free(env->philo);
	if (env)
		free(env);
}

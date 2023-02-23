/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:51 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 16:49:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	usleep(ms * 1000);
}

static void	set_dead(t_env *env, int s)
{
	int	index;

	index = 0;
	while (index < env->nb_philo)
	{
		pthread_mutex_lock(&env->philo[index].death);
		if (s == 1)
			env->philo[index].dead = 2;
		index++;
	}
}

int	check_dead(t_env *env)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < env->nb_philo)
	{
		if (env->philo[index].dead == 1)
		{
			set_dead(env, 0);
			return (1);
		}
		if (env->philo[index].dead == 2)
			count++;
		index++;
	}
	if (count == env->nb_philo)
	{
		set_dead(env, 1);
		return (1);
	}
	return (0);
}

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

long long	timestamp(t_env *env)
{
	long long	time;

	gettimeofday(&env->tv, NULL);
	time = 1000000 * env->tv.tv_sec + env->tv.tv_usec;
	time = (time - env->time_start) * 0.001;
	return (time);
}

void	print_msg(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->stop_cond == 0)
		printf("%lld %d%s", timestamp(philo->data), philo->pos, str);
	pthread_mutex_unlock(&philo->data->print);
}

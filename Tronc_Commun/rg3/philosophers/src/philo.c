/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:02:25 by lcompieg          #+#    #+#             */
/*   Updated: 2023/05/31 15:40:29 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	tmstmp_env(t_env *env)
{
	long long	time;

	gettimeofday(&env->tv, NULL);
	time = 1000000 * env->tv.tv_sec + env->tv.tv_usec;
	time = (time - env->time_start) * 0.001;
	return (time);
}

void	free_env(t_env *env)
{
	int	index;

	index = 0;
	while (index < env->nb_philo)
	{
		pthread_mutex_destroy(&env->philo[index].fork);
		pthread_mutex_destroy(&env->philo[index].stop);
		index++;
	}
	if (env->philo)
		free(env->philo);
	pthread_mutex_destroy(&env->print);
	if (env)
		free(env);
}

int	one_philo(t_env *env)
{
	long long	start;

	start = tmstmp_env(env);
	usleep(env->time_to_die * 1000);
	printf("%lld 1 is dead.\n", tmstmp_env(env) - start);
	free(env);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 5 || argc == 6)
	{
		env = malloc(sizeof(t_env));
		if (!env)
			return (-1);
		if (!parsing(env, argv, argc))
			return (-1);
		if (env->nb_philo == 1)
			return (one_philo(env));
		if (!philo_life(env))
			return (-1);
		free_env(env);
		return (1);
	}
	else
	{
		printf("Usage : ./philo nb_philo tm_die tm_eat tm_sleep [nb_must_eat]");
		return (-1);
	}
	return (0);
}

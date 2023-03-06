/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:07:50 by lcompieg          #+#    #+#             */
/*   Updated: 2023/03/06 23:22:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	is_digit(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if ('0' < str[index] && str[index] > '9')
			return (0);
		index++;
	}
	return (1);
}

static int	init_var(t_philo *philo, int index)
{
	philo->pos = index + 1;
	philo->m_eat = 0;
	philo->last_eat = 0;
	if (pthread_mutex_init(&philo->stop, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&philo->fork, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&philo->death, NULL) != 0)
		return (0);
	philo->f_taken = 0;
	return (1);
}

static int	create_philo(t_env *env)
{
	int	index;

	index = 0;
	gettimeofday(&env->tv, NULL);
	env->time_start = 1000000 * env->tv.tv_sec + env->tv.tv_usec;
	if (pthread_mutex_init(&env->print, NULL) != 0)
		return (0);
	env->philo = malloc(sizeof(t_philo) * env->nb_philo);
	if (!env->philo)
		return (0);
	while (index < env->nb_philo)
	{
		env->philo[index].start = env->time_start;
		env->philo[index].data = env;
		if (!init_var(&env->philo[index], index))
			return (0);
		index++;
	}
	return (1);
}

int	parsing(t_env *env, char **argv, int argc)
{
	if (!is_digit(argv[1]) || !is_digit(argv[2]) || \
	!is_digit(argv[3]) || !is_digit(argv[4]))
		return (0);
	env->nb_philo = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!is_digit(argv[5]))
			return (0);
		env->nb_eat = ft_atoi(argv[5]);
	}
	else
		env->nb_eat = 0;
	if (env->nb_philo < 1 || env->time_to_die < 0 || env->time_to_eat < 0
		|| env->time_to_sleep < 0 || env->nb_eat < 0)
		return (0);
	env->stop_cond = 0;
	env->count = 0;
	if (!create_philo(env))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:02:25 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/17 20:07:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	free_env(t_env *env)
{
	int	index;

	index = 0;
	while (index < env->nb_philo)
	{
		pthread_mutex_destroy(&env->philo[index]->fork_l);
		pthread_mutex_destroy(&env->philo[index]->fork_r);
		pthread_mutex_destroy(&env->philo[index]->stop);
		if (env->philo[index])
			free(env->philo[index]);
	}
	if (env->philo)
		free(env->philo);
	if (env)
		free(env);
}

void	display_env(t_env *env)
{
	int	index;

	index = 0;
	while (index < env->nb_philo)
	{
		printf("%d\n", env->philo[index]->pos);
		index++;
	}
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
		create_philo(env);
		free_env(env);
	}
	else
	{
		printf("Usage : ./philo nb_philo tm_die tm_eat tm_sleep [nb_must_eat]");
		return (-1);
	}
	return (0);
}

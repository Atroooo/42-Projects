/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:07:50 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/13 15:42:52 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*routine(void *arg)
{
	int	nb;

	nb = *(int*)arg;
	printf("%d\n", nb);
	return (NULL);
}

static void	create_philo(t_env *env)
{
	int	index;

	index = 0;
	env->philo = malloc(sizeof(pthread_t) * env->nb_philo);
	while (index < env->nb_philo)
	{
		if (pthread_create(&env->philo[index], NULL, &routine, &index) != 0)
			return ;
		if (pthread_join(env->philo[index], NULL) != 0)
			return ;
		index++;
	}
}

void	parsing(t_env *env, char **argv, int argc)
{
	env->nb_philo = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		env->nb_eat = ft_atoi(argv[5]);
	else
		env->nb_eat = 0;
	create_philo(env);
}

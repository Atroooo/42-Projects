/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:07:50 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/17 20:18:55 by marvin           ###   ########.fr       */
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
	return (1);
}

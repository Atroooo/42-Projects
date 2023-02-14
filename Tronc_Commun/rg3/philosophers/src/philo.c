/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:02:25 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/14 20:44:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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
		if (!parsing(env, argv, argc))
			return (-1);
		display_env(env);
	}
	else
	{
		printf("Error");
		return (-1);
	}
	return (0);
}

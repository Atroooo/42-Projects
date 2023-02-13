/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:02:25 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/13 15:24:40 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_env	*env;
	
	if (argc == 5 || argc == 6)
	{
		env = malloc(sizeof(t_env));
		parsing(env, argv, argc);
	}
	else
	{
		printf("Error");
		return (-1);
	}
	return (0);
}

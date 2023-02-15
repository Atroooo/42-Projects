/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rountine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:32:12 by marvin            #+#    #+#             */
/*   Updated: 2023/02/15 21:32:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*routine(void *philo)
{
	pthread_mutex_t	mutex;
	
	while(!philo->dead) //ou que tous les philosophes ont mangé
	{
		//action
		//mange : l'un des voisins ne pourra pas manger parce que celui qui mange va lui emprunter sa fourchette : mange le temps en ms
		//dors : la fourchette du philo peut être emprunter : dors le temps en ms
		//pense	: la fourchette du philo peut être emprunter : pense le temps en ms
	}
	return (NULL);
}

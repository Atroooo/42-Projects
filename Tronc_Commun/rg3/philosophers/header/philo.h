/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:53:33 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/15 22:06:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//Librairies
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef	struct s_philo
{
	int				pos;
	int				dead;
	int				nb_eat;
	int				last_eat;
	pthread_t		th;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	fork_r;
} t_philo;


typedef struct s_env
{
	t_philo	**philo;
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_eat;
	pthread_mutex_t	m_eat;
} t_env;

//Parsing functions
int		ft_atoi(const char *str);
int		parsing(t_env *env, char **argv, int argc);

//Thread functions
void	create_philo(t_env *env);
void	*routine(void *philo);

//Free functions

#endif
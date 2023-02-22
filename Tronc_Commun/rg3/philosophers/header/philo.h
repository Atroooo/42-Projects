/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:53:33 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/22 21:23:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Librairies */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		th;
	int				pos;
	int				m_eat;
	long long		last_eat;
	int				dead;
	int				f_taken;
	int				r_taken;
	int				l_taken;
	int				think;
	pthread_mutex_t	fork;
	pthread_mutex_t	death;
	struct s_env	*data;
}	t_philo;

typedef struct s_env
{
	t_philo			*philo;
	int				nb_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				nb_eat;
}	t_env;

/* Parsing functions */
int			ft_atoi(const char *str);
int			parsing(t_env *env, char **argv, int argc);

/* Thread functions */
int			philo_life(t_env *env);

/* Utils functions */
long long	timestamp(void);
void		ft_usleep(int ms);

/* Actions functions */
void		philo_sleep_think(t_philo *philo, long long start);
int			take_fork(t_philo *philo, long long start);
void		take_fork_s(t_philo *philo);
void		lock_fork(t_philo *philo, t_philo *next_philo, int s);
void		philo_eat(t_philo *philo, long long start);
void		eat_left(t_philo *philo);
void		eat_right(t_philo *philo);

/* Death functions */
int			is_dead(t_philo *philo);
int			check_dead(t_env *env);

#endif
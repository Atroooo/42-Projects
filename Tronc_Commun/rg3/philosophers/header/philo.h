/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:53:33 by lcompieg          #+#    #+#             */
/*   Updated: 2023/03/02 13:52:02 by lcompieg         ###   ########.fr       */
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
	long long		start;
	int				pos;
	int				m_eat;
	long long		last_eat;
	int				f_taken;
	int				think;
	pthread_mutex_t	stop;
	pthread_mutex_t	fork;
	pthread_mutex_t	death;
	struct s_env	*data;
}	t_philo;

typedef struct s_env
{
	t_philo			*philo;
	pthread_mutex_t	print;
	struct timeval	tv;
	int				stop_cond;
	int				nb_philo;
	int				nb_eat;
	int				count;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		time_start;
}	t_env;

/* Parsing functions */
int			ft_atoi(const char *str);
int			parsing(t_env *env, char **argv, int argc);

/* Thread functions */
int			philo_life(t_env *env);

/* Utils functions */
long long	timestamp(t_env *env);
void		print_msg(char *str, t_philo *philo);

/* Actions functions */
void		philo_sleep_think(t_philo *philo);
int			take_fork(t_philo *philo);
void		depose_fork(t_philo *philo);
int			lock_fork(t_philo *philo, t_philo *next_philo);
void		unlock_fork(t_philo *philo, t_philo *next_philo);
void		philo_eat(t_philo *philo);
int			check_dead(t_env *env);

#endif
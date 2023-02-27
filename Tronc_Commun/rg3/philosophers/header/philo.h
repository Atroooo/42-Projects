/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:53:33 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/27 20:47:47 by marvin           ###   ########.fr       */
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
	int				f_taken;
	int				think;
	pthread_mutex_t	stop;
	pthread_mutex_t	fork;
	struct s_env	*data;
}	t_philo;

typedef struct s_env
{
	t_philo			*philo;
	pthread_mutex_t	death;
	int				stop_cond;
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
void		print_msg(char *str, long long st, t_philo *philo);

/* Actions functions */
void		philo_sleep_think(t_philo *philo, long long start);
int			take_fork(t_philo *philo, long long start);
int			lock_fork(t_philo *philo, t_philo *next_philo);
void		unlock_fork(t_philo *philo, t_philo *next_philo);
void		philo_eat(t_philo *philo, long long start);
int			check_dead(t_env *env);

#endif
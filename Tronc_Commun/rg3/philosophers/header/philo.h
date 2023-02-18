/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:53:33 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/18 17:13:01 by lcompieg         ###   ########.fr       */
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
	pthread_t		th;
	int				pos;
	int				m_eat;
	long long		last_eat;
	int				dead;
	pthread_mutex_t	fork;
	int				f_taken;
	int				r_taken;
	int				l_taken;
	pthread_mutex_t	stop;
	struct s_env	*data;
} t_philo;


typedef struct s_env
{
	t_philo		*philo;
	int			nb_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			nb_eat;
} t_env;

//Parsing functions
int			ft_atoi(const char *str);
int			parsing(t_env *env, char **argv, int argc);

//Thread functions
int			philo_life(t_env *env);

//Utils functions
long long	timestamp(void);
void		ft_usleep(int ms);
void		philo_sleep_think(t_philo *philo, long long start);
void 		philo_eat(t_philo *philo, long long start);
int			take_fork(t_philo *philo, long long start);
int			is_dead(t_philo *philo);
void		set_dead(t_env *env, int s);

#endif
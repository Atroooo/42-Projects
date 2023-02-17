/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:53:33 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/17 20:31:16 by marvin           ###   ########.fr       */
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
	pthread_mutex_t	fork_l;
	int				l_taken;
	pthread_mutex_t	fork_r;
	int				r_taken;
	pthread_mutex_t	stop;
	struct s_env	*data;
} t_philo;


typedef struct s_env
{
	t_philo		**philo;
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
void		create_philo(t_env *env);

//Utils functions
long long	timestamp(void);
void		ft_usleep(int ms);
void		philo_sleep_think(t_philo *philo);
void 		philo_eat(t_philo *philo);
void		take_fork(t_philo *philo);
int			is_dead(t_philo *philo);
void    	print(t_philo *philo, char *str);

#endif
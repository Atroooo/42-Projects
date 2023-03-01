/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:54:53 by lcompieg          #+#    #+#             */
/*   Updated: 2023/03/01 20:42:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/header/libft.h"

typedef struct	s_data
{
	pid_t	client_pid;
	char 	*str;
	char	c;
	int		bits;
	int		state;
	int		len;
}	t_data;

#endif
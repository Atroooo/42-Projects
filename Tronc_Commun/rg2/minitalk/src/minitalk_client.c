/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:08:20 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/08 23:36:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	handler(unsigned char c, pid_t pid)
{
	int				i;
	unsigned int	base;

	i = 7;
	base = 128;
	while (i >= 0)
	{
		if (c < base)
			kill(pid, SIGUSR1);		
		else
		{
			kill(pid, SIGUSR2);
			c = c - base;
		}
		base = base / 2;
		i--;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int		index;
	int		server_pid;

	index = 0;
	if (argc != 3 || !ft_strlen(argv[2]))
		return (ft_printf("Use : ./client [PID] [STR]"), -1);
	server_pid = ft_atoi(argv[1]);
	while (argv[2][index])
	{
		handler(argv[2][index], server_pid);
		index++;
	}
	handler('\n', server_pid);
	return (0);
}

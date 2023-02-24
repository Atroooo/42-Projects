/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:08:20 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/24 21:41:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (sig == SIGUSR1)
	{
		usleep(100);
		ft_printf("signal recu, %d \n", (int)sig);
	}		
}

void	send_c(unsigned char c, pid_t pid)
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
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int		index;
	int		server_pid;

	index = 0;
	if (argc != 3 || !ft_strlen(argv[2]))
		return (ft_printf("Use : ./client [PID] [STR]"), -1);
	server_pid = ft_atoi(argv[1]);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (argv[2][index])
	{
		send_c(argv[2][index], server_pid);
		index++;
	}
	send_c('\n', server_pid);
	return (0);
}

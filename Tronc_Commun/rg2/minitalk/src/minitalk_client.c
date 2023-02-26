/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:08:20 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/26 21:39:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

int	g_recep_confirm = 1;

void	handler(int sig, siginfo_t *info, void *context)
{	
	static int	received = 0;

	(void) info;
	(void) context;
	if (sig == SIGUSR1)
	{
		g_recep_confirm = 1;
		received++;
	}
	if (sig == SIGUSR2)
	{
		g_recep_confirm = 0;
		ft_printf("Server received %d chars.\n", received);
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
		if (c < base && g_recep_confirm == 1)
		{
			kill(pid, SIGUSR1);
			g_recep_confirm = 0;
			base = base / 2;
			i--;
		}
		else if (g_recep_confirm == 1)
		{
			kill(pid, SIGUSR2);
			c = c - base;
			g_recep_confirm = 0;
			base = base / 2;
			i--;
		}
		pause();
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					index;
	int					server_pid;

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
	send_c(0, server_pid);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:08:20 by lcompieg          #+#    #+#             */
/*   Updated: 2023/03/01 20:40:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

int	g_recep_confirm = 0;

void	handler(int sig, siginfo_t *info, void *context)
{	
	static int	received = 0;

	(void) info;
	(void) context;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		g_recep_confirm = 1;
		received++;
	}
	if (sig == SIGUSR1)
	{
		ft_printf("Server received %d bytes.\n", received);
		exit(0);
	}
}

void	send_len(size_t len, pid_t pid)
{
	int	bit;

	bit = 32;
	while (--bit >= 0)
	{
		if (len >> bit & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_recep_confirm)
			pause();
		g_recep_confirm = 0;
	}
}

void	send_str(char *str, pid_t pid)
{
	int	index;
	int	bit;

	index = -1;
	while (str[++index])
	{
		bit = 8;
		while (--bit >= 0)
		{
			if (str[index] >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (!g_recep_confirm)
				pause();
			g_recep_confirm = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (ft_printf("Use : ./client [PID] [STR]"), -1);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || server_pid > INT_MAX)
	{
		ft_printf("Invalid PID\n");
		exit (EXIT_FAILURE);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_len(ft_strlen(argv[2]), server_pid);
	send_str(argv[2], server_pid);
	return (0);
}

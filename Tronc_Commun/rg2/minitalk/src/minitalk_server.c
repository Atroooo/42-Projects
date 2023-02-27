/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:15:52 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/27 22:01:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static void handler_utils(int *client_pid)
{
	kill(*client_pid, SIGUSR2);
	write(1, "\n", 1);
	*client_pid = 0;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		c = c | 128 >> i;
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			handler_utils(&client_pid);
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Use : ./server");
		return (-1);
	}
	pid = getpid();
	ft_printf("Server PID is %d\n", pid);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

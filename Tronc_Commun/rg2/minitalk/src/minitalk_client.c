/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:08:20 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/24 22:21:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			server_pid = 0;
	static unsigned char	c = 0;
	static char 			*str;
	unsigned int			base;
	int	index = 0;
	
	str = (char *) context;
	if (!server_pid)
		server_pid = info->si_pid;
	if (sig == SIGUSR2)
		exit(0);
	while (str[index])
	{
		c = str[index];
		printf("%c\n", c);
		i = 7;
		base = 128;
		while (i >= 0)
		{
			if (sig == SIGUSR1)
			{
				if (c < base)
					kill(server_pid, SIGUSR1);
				else
				{
					kill(server_pid, SIGUSR2);
					c = c - base;
				}
				base = base / 2;
				i--;
			}
			else
				exit(1);	
		}
		str++;
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
	int		server_pid;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (ft_printf("Use : ./client [PID] [STR]"), -1);
	server_pid = ft_atoi(argv[1]);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	send_c(argv[2][0], server_pid);
	sigaction(SIGUSR1, &sa, (void *)argv[2] + 1);
	sigaction(SIGUSR2, &sa, (void *)argv[2] + 1);
	while (1)
		sleep(10);
	return (0);
}

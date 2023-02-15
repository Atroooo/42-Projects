/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:15:52 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/15 13:02:09 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	handler(int sig)
{
	static int	i = 0;
	static char	c = 0;
	
	if (sig == SIGUSR2)
		c = c | 128 >> i;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
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
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SI_USER);
	sa.sa_flags = SI_USER;
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(10);
	return (0);
}

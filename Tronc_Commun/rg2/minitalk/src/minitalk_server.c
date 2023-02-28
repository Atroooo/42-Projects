/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:15:52 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/28 17:44:56 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static t_data	g_data;

static void	init_var(void)
{
	g_data.len = 0;
	g_data.state = 0;
	g_data.client_pid = 0;
}

static void	get_len(int signal)
{
	static int	bit = 32;
	
	g_data.len = g_data.len * 2 + signal;
	if (--bit == 0)
	{
		bit = 32;
		g_data.str = malloc(sizeof(char) * (g_data.len + 1));
		g_data.state = 2;
	}
	kill(g_data.client_pid, SIGUSR1);
}

static void get_str(int sig)
{
	static char	c = 0;
	static int	bit = 8;
	static int	i = 0;
	
	c = c * 2 + sig;
	if (--bit == 0)
	{
		g_data.str[i] = c;
		i++;
		c = 0;
		bit = 8;
	}
	if (i == g_data.len)
	{
		g_data.str[i] = '\0';
		ft_printf("%s\n", g_data.str);
		free(g_data.str);
		kill(g_data.client_pid, SIGUSR2);
		i = 0;
		bit = 8;
		init_var();
	}
	else
		kill(g_data.client_pid, SIGUSR1);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	int	signal;
	
	(void)context;
	if (g_data.state == 0)
	{
		g_data.client_pid = info->si_pid;
		g_data.state = 1;
	}
	if (sig == SIGUSR2)
		signal = 1;
	if (sig == SIGUSR1)
		signal = 0;
	if (g_data.state == 1)
		get_len(signal);
	if (g_data.state == 2)
		get_str(signal);
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
	init_var();
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

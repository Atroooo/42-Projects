/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:15:52 by lcompieg          #+#    #+#             */
/*   Updated: 2023/03/14 14:44:19 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

static t_data	g_data;

void	init_var(void)
{
	g_data.len = 0;
	g_data.bits = 8;
	g_data.state = 0;
	g_data.client_pid = 0;
	g_data.c = 0;
	g_data.str = NULL;
}

int	get_len(int len, int signal)
{
	static int	bits = 32;

	len = len * 2 + signal;
	bits--;
	if (bits == 0)
	{
		g_data.len = len;
		g_data.bits = 8;
		g_data.str = ft_calloc(len + 1, sizeof(char));
		if (!g_data.str)
		{
			ft_printf("Malloc error.\n");
			exit(1);
		}
		g_data.state = 2;
		bits = 32;
	}
	kill(g_data.client_pid, SIGUSR2);
	return (len);
}

void	get_str(int signal)
{
	static int	i = 0;

	g_data.c = g_data.c * 2 + signal;
	g_data.bits--;
	if (g_data.bits == 0)
	{
		g_data.str[i] = g_data.c;
		g_data.c = 0;
		g_data.bits = 8;
		i++;
	}
	if (i == g_data.len)
	{
		g_data.str[i] = '\0';
		ft_printf("%s\n", g_data.str);
		free(g_data.str);
		kill(g_data.client_pid, SIGUSR1);
		i = 0;
		init_var();
	}
	else
		kill(g_data.client_pid, SIGUSR2);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	int	signal;

	(void) context;
	if (sig == SIGUSR1)
		signal = 0;
	else if (sig == SIGUSR2)
		signal = 1;
	if (g_data.client_pid != info->si_pid)
		g_data.state = 0;
	if (g_data.state == 0)
	{
		g_data.client_pid = info->si_pid;
		g_data.state = 1;
	}
	if (g_data.state == 1)
		g_data.len = get_len(g_data.len, signal);
	else if (g_data.state == 2)
		get_str(signal);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Use : ./server");
		return (-1);
	}
	init_var();
	ft_printf("Server PID is %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

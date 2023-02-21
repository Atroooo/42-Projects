/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:18:39 by marvin            #+#    #+#             */
/*   Updated: 2023/02/15 22:18:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static int	check_args(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	int				j;

	if (haystack == NULL && len == 0)
		return (0);
	i = 0;
	if (needle[i] == '\0')
		return (0);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0'
			&& i + j < len)
			j++;
		if (needle[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static void	parent(char **argv, char **env, int *p_fd)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		ft_putstr_fd("Error File", 2);
		exit(-1);
	}
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	if (ft_strlen(argv[3]) == 0 && ft_strlen(argv[2]) == 0)
	{
		exit(0); //close fd
	}
	exec_cmd(argv[3], env);
}

static void	child(char **argv, char **env, int *p_fd)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		ft_putstr_fd("Error File", 2);
		exit(-1);
	}
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	if (ft_strlen(argv[2]) == 0 && ft_strlen(argv[3]) == 0)
	{
		exit(0); //close fd
	}
	exec_cmd(argv[2], env);
}

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	int	p_fd[2];
	pid_t	pid;

	if (!env[0])
		print_error("Environnement Error");
	if (argc != 5)
	{
		ft_putstr_fd("Usage : ./pipex infile \"command\" \"command\" outfile", 2);
		exit(0);
	}
	if (pipe(p_fd) == -1)
		print_error("Error Pipe");
	if (check_args(argv[2], "./", 2) || \
		check_args(argv[3], "./", 2))
		print_error("Error Command");
	pid = fork();
	if (pid == -1)
		print_error("Error Fork");
	if (pid == 0)
		child(argv, env, p_fd);
	parent(argv, env, p_fd);
}

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

static void	exec_cmd(char *cmd, char **env)
{
	char	**cmd_s;
	char	*path;

	cmd_s = ft_split(cmd, ' ');
	path = get_path(cmd_s[0], env);
	if (execve(path, cmd_s, env) == -1)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(cmd_s[0], 2);
		free_str(cmd_s);
		exit(0);
	}
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
	exec_cmd(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	int	p_fd[2];
	int	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Usage : ./pipex infile \"command\" \"command\" outfile", 2);
		exit(0);
	}
	if (pipe(p_fd) == -1)
	{
		ft_putstr_fd("Error Pipe", 2);
		exit(-1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error Fork", 2);
		exit(-1);
	}
	if (!pid)
		child(argv, env, p_fd);
	parent(argv, env, p_fd);
}

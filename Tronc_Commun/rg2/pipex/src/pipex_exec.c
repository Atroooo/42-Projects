/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:42:25 by marvin            #+#    #+#             */
/*   Updated: 2023/02/21 19:42:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static char	*get_env(char **env)
{
	int		i;
	int		j;
	char	*substr;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		substr = ft_substr(env[i], 0, j);
		if (ft_strncmp(substr, "PATH", ft_strlen(substr)) == 0)
		{
			free(substr);
			return (env[i] + j + 1);
		}
		free(substr);
		i++;
	}
	return (NULL);
}

static char	*get_path(char *cmd, char **env)
{
	int		index;
	char	*exec;
	char	**all_path;
	char	*path_part;
	char	**cmd_s;

	index = 0;
	all_path = ft_split(get_env(env), ':');
	cmd_s = ft_split(cmd, ' ');
	while (all_path[index])
	{
		path_part = ft_strjoin(all_path[index], "/");
		exec = ft_strjoin(path_part, cmd_s[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_str(cmd_s);
			return (exec);
		}
		free(exec);
		index++;
	}
	free_str(all_path);
	free_str(cmd_s);
	return (cmd);
}

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


void	parent(char **argv, char **env, int *p_fd)
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
	if (!args_nempty(argv[3]))
		exit(0);
    printf("\n\noui parent\n\n");
	exec_cmd(argv[3], env);
}

void	child(char **argv, char **env, int *p_fd)
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
	if (!args_nempty(argv[2]))
		exit(0);
    printf("\n\noui enfant\n\n");
	exec_cmd(argv[2], env);
}

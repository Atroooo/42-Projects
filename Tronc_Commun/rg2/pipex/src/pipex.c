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

static void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

//si une commande vide : ne pas fork et direct execute parent
int	main(int argc, char **argv, char **env)
{
	int	p_fd[2];
	pid_t	pid;

	if (!env[0])
		print_error("Environnement error");
	if (argc != 5)
	{
		ft_putstr_fd("Usage : ./pipex infile \"command\" \"command\" outfile", 2);
		exit(0);
	}
	if (pipe(p_fd) == -1)
		print_error("Pipe error");
	if (check_args(argv[2], "./", 2) || \
		check_args(argv[3], "./", 2))
		print_error("Command error");
	pid = fork();
	if (pid == -1)
		print_error("Fork error");
	if (pid == 0)
		child(argv, env, p_fd);
	parent(argv, env, p_fd);
	waitpid(pid, NULL, 0);
	waitpid(0, NULL, 0);
}

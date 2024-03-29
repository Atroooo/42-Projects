/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:39:48 by vgonnot           #+#    #+#             */
/*   Updated: 2023/03/29 15:27:43 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	set_up_pipe(t_env *st)
{
	int	i;

	i = 0;
	while (i < st->nbr_cmd - 1)
	{
		st->fd[i] = malloc(sizeof(int) * 2);
		if (st->fd[i] == NULL || pipe(st->fd[i]) == -1)
			free_env_exit(st, i);
		i++;
	}
}

void	set_up_struct(t_env *st, int argc, char **argv)
{
	st->nbr_cmd = argc - 3;
	st->hdoc = heredoc(st, argv);
	if (st->hdoc == 1 && argc < 6)
		exit(ft_printf("Error : not enough arguments\n"));
	st->actual_pipe = 0;
	st->pid = malloc(sizeof(int) * (st->nbr_cmd + 1));
	if (st->pid == NULL)
		free_env_exit(st, -1);
	st->fd = malloc(sizeof(int *) * (st->nbr_cmd));
	if (st->fd == NULL)
	{
		free(st->pid);
		free_env_exit(st, -1);
	}
	set_up_pipe(st);
}

void	open_files(int argc, char **argv, t_env *st)
{
	int	hdoc;

	hdoc = ft_strcmp(argv[1], "here_doc");
	if (hdoc == 0)
		st->infile = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		st->infile = open(argv[1], O_RDWR);
	if (st->infile == -1)
	{
		ft_printf("Cannot open file : %s\n", argv[1]);
		free(st);
		exit(EXIT_FAILURE);
	}
	if (hdoc == 0)
		st->outfile = open(argv[argc -1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		st->outfile = open(argv[argc -1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (st->outfile == -1)
		quit_function(st, 0);
}

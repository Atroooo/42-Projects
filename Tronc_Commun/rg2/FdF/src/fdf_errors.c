/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:04:47 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/13 14:16:43 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	clear_struct(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y * env->index_x + x < env->idx_max)
	{
		if (x == env->index_x)
		{	
			y++;
			x = 0;
		}
		if (env->map[y * env->index_x + x])
			free(env->map[y * env->index_x + x]);
		x++;
	}
	if (env->map)
		free(env->map);
	free(env);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error(t_env *env)
{
	ft_printf("Error : %s\n", strerror(errno));
	free(env);
	close(0);
	close(1);
	close(2);
	exit(0);
}

void	error_parsing(t_env *env, int fd)
{
	int	index;

	index = 0;
	while (index < env->idx_max)
	{
		if (env->map[index])
			free(env->map[index]);
		index++;
	}
	if (env->map)
		free(env->map);
	free(env);
	close(fd);
	close(0);
	close(1);
	close(2);
	exit(0);
}

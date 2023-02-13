/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:33:53 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/04 16:27:45 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static int	get_step(double dx, double dy)
{
	if (fabs(dx) > fabs(dy))
		return (fabs(dx));
	else
		return (fabs(dy));
}

static double	get_right_coord(t_env *env, int index, char c)
{
	if (c == 'x')
	{
		if (env->map[index + 1]->posx)
			return (env->map[index + 1]->posx);
	}
	else if (c == 'y')
	{
		if (env->map[index + 1]->posy)
			return (env->map[index + 1]->posy);
	}
	return (0);
}

static double	get_bottom_coord(t_env *env, int index, char c)
{
	if (c == 'x')
	{
		if (index + env->index_x < env->idx_max && \
			env->map[index + env->index_x]->posx)
			return (env->map[index + env->index_x]->posx);
	}
	else if (c == 'y')
	{
		if (index + env->index_x < env->idx_max && \
			env->map[index + env->index_x]->posy)
			return (env->map[index + env->index_x]->posy);
	}
	return (0);
}

static void	draw_line(t_env *env, int x, int y, \
		double (*function) (t_env *, int, char))
{
	double	tempx;
	double	tempy;
	double	step;
	int		idx;
	int		i;

	idx = y * env->index_x + x;
	if (idx >= env->idx_max)
		return ;
	env->map[idx]->dx = (*function)(env, idx, 'x') - env->map[idx]->posx;
	env->map[idx]->dy = (*function)(env, idx, 'y') - env->map[idx]->posy;
	step = get_step(env->map[idx]->dx, env->map[idx]->dy);
	i = 0;
	tempx = env->map[idx]->posx;
	tempy = env->map[idx]->posy;
	while (i < step)
	{
		if (0 < tempx && tempx < RES_X && 0 < tempy && tempy < RES_Y)
			my_mlx_pixel_put(env, tempx, tempy, env->map[idx]->color);
		tempx += (env->map[idx]->dx / step);
		tempy += (env->map[idx]->dy / step);
		i++;
	}
}

void	print_lines(t_env *env)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y * env->index_x + x < env->idx_max)
	{
		if (x == env->index_x - 1)
		{
			if (y * env->index_x + x < env->idx_max - 1)
				draw_line(env, x, y, get_bottom_coord);
			x = 0;
			y++;
		}
		if (y < env->index_y - 1)
			draw_line(env, x, y, get_bottom_coord);
		draw_line(env, x, y, get_right_coord);
		x++;
	}
}

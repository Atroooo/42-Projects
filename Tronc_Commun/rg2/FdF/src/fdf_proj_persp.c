/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj_persp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:43:40 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/08 13:31:51 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	calcul_proj(t_env *env, int index)
{
	t_point	*point;
	double	angle;

	point = env->map[index];
	angle = 90 * 0.5 / 180.0 * 3.1415;
	point->x = point->x * (1 / (tan(angle / 2) * (RES_X / RES_Y)));
	point->y = point->y * (1 / tan(angle / 2));
	point->z = point->z * (Z_FAR / (Z_FAR - Z_NEAR)) + \
		1 * ((-Z_FAR * Z_NEAR) / (Z_FAR - Z_NEAR));
	point->w = point->z;
	point->posx = (((point->x / point->w) + 1) * 0.5);
	point->posy = (((point->y / point->w) + 1) * 0.5);
}

static void	center_coord(t_env *env, double max_coordx, double max_coordy)
{
	int	index;

	index = 0;
	while (index < env->idx_max)
	{
		env->map[index]->posx += fabs((RES_X - max_coordx) / 1.2);
		env->map[index]->posy += fabs((RES_Y - max_coordy) / 1.4);
		pixel_put(env, index);
		index++;
	}
}

static void	scale_coord(t_env *env)
{
	double	max_coordx;
	double	max_coordy;
	int		index;

	max_coordx = 0.0;
	max_coordy = 0.0;
	index = 0;
	while (index < env->idx_max)
	{
		env->map[index]->posx /= env->max_posx;
		env->map[index]->posy /= env->max_posy;
		env->map[index]->posx = env->map[index]->posx * \
			RES_X * 0.5 * env->zoom + env->current_x;
		env->map[index]->posy = env->map[index]->posy * \
			RES_Y * 0.5 * env->zoom + env->current_y;
		if (env->map[index]->posx > max_coordx)
			max_coordx = env->map[index]->posx;
		if (env->map[index]->posy > max_coordy)
			max_coordy = env->map[index]->posy;
		index++;
	}
	center_coord(env, max_coordx, max_coordy);
}

void	print_coords_proj(t_env *env)
{
	int	index;

	index = 0;
	env->max_posx = 0.0;
	env->max_posy = 0.0;
	while (index < env->idx_max)
	{
		translate(env, index);
		rotate_coord(env, index);
		center(env, index);
		calcul_proj(env, index);
		if (fabs(env->map[index]->posx) > env->max_posx)
			env->max_posx = fabs(env->map[index]->posx);
		if (fabs(env->map[index]->posy) > env->max_posy)
			env->max_posy = fabs(env->map[index]->posy);
		index++;
	}
	scale_coord(env);
}

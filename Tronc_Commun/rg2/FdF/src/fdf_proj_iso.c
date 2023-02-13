/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:28:16 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/04 16:28:16 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	calculate_coord(t_env *env, int index)
{
	t_point	*point;

	point = env->map[index];
	point->posx = (0.7071) * (point->x - point->y);
	point->posy = (0.8164 * point->z) - (0.4082) \
		* (point->x + point->y);
}

static void	scale_coord(t_env *env)
{
	int		index;

	index = 0;
	while (index < env->idx_max)
	{
		env->map[index]->posx = env->map[index]->posx * \
			env->scale * env->zoom + env->current_x + \
			fabs((RES_X - env->max_posx) / 2);
		env->map[index]->posy = env->map[index]->posy * \
			env->scale * env->zoom + env->current_y + \
			fabs(RES_Y - env->max_posy) * env->mult;
		pixel_put(env, index);
		index++;
	}
}

void	print_coords_iso(t_env *env)
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
		calculate_coord(env, index);
		if (fabs(env->map[index]->posx) > env->max_posx)
			env->max_posx = fabs(env->map[index]->posx);
		if (fabs(env->map[index]->posy) > env->max_posy)
			env->max_posy = fabs(env->map[index]->posy);
		index++;
	}
	scale_coord(env);
}

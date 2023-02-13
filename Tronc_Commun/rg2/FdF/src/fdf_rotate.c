/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:28:36 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/07 13:33:01 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	rotate(int keycode, t_env *env)
{
	if (keycode == Key_Q)
		env->rotatex += INC_ROT;
	if (keycode == Key_W)
		env->rotatex -= INC_ROT;
	if (keycode == Key_A)
		env->rotatey += INC_ROT;
	if (keycode == Key_S)
		env->rotatey -= INC_ROT;
	if (keycode == Key_Z)
		env->rotatez += INC_ROT;
	if (keycode == Key_X)
		env->rotatez -= INC_ROT;
	update_wdw(env);
}

void	rotate_coord(t_env *env, int index)
{
	t_point	*point;

	point = env->map[index];
	point->x = (point->b_x * (cos(env->rotatez) * cos(env->rotatey)) + \
				point->b_y * ((sin(env->rotatex) * sin(env->rotatey) * \
				cos(env->rotatez)) - (cos(env->rotatex) * sin(env->rotatez))) + \
				point->b_z * ((cos(env->rotatex) * sin(env->rotatey) * \
				cos(env->rotatez)) + (sin(env->rotatex) * sin(env->rotatez))));
	point->y = (point->b_x * (cos(env->rotatey) * sin(env->rotatez)) + \
				point->b_y * ((sin(env->rotatex) * sin(env->rotatey) * \
				sin(env->rotatez)) + (cos(env->rotatex) * cos(env->rotatez))) + \
				point->b_z * ((cos(env->rotatex) * sin(env->rotatey) * \
				sin(env->rotatez)) - (sin(env->rotatex) * cos(env->rotatez))));
	point->z = (point->b_x * (-sin(env->rotatey)) + \
				point->b_y * (sin(env->rotatex) * \
				cos(env->rotatey)) + point->b_z * \
				(cos(env->rotatex) * cos(env->rotatey)));
}

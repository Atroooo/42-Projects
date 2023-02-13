/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:13:03 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/04 16:27:49 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->addr + (y * env->line_length + x * (env->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	pixel_put(t_env *env, int index)
{
	if (0 < env->map[index]->posx && env->map[index]->posx < RES_X && \
		0 < env->map[index]->posy && env->map[index]->posy < RES_Y)
		my_mlx_pixel_put(env, env->map[index]->posx, \
			env->map[index]->posy, env->map[index]->color);
}

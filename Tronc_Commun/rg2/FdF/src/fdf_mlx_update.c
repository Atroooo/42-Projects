/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:28:01 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/04 16:28:01 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	project(t_env *env)
{
	if (env->proj == 0)
		print_coords_iso(env);
	else
		print_coords_proj(env);
	print_lines(env);
}

void	update_wdw(t_env *env)
{
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, RES_X, RES_Y);
	if (!env->img)
		mlx_close(env);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
		&env->line_length, &env->endian);
	if (!env->addr)
		mlx_close(env);
	project(env);
	mlx_clear_window(env->mlx, env->mlx_win);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img, \
		0, 0);
}

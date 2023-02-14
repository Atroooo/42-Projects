/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:57:09 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/14 16:58:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	switch_proj(t_env *env)
{
	if (env->proj == 0)
		env->proj = 1;
	else
		env->proj = 0;
	update_wdw(env);
}

int	mlx_close(t_env *env)
{
	if (env->mlx && env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->mlx && env->mlx_win)
		mlx_destroy_window(env->mlx, env->mlx_win);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	close(0);
	close(1);
	close(2);
	clear_struct(env);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == Key_Space)
		reset_wdw(env);
	if (keycode == Key_Right || keycode == Key_Down || \
		keycode == Key_Up || keycode == Key_Left)
		move_in_wdw(keycode, env);
	else if (keycode == Key_Plus || keycode == Key_Minus)
		zoom_in_wdw(keycode, env);
	else if (keycode == Key_Z || keycode == Key_A || keycode == Key_S \
		|| keycode == Key_Q || keycode == Key_X || keycode == Key_W)
		rotate(keycode, env);
	else if (keycode == Key_Escape)
		mlx_close(env);
	else if (keycode == Key_T)
		switch_proj(env);
	return (0);
}

void	mlx_setup(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
	{
		clear_struct(env);
		exit(0);
	}
	env->mlx_win = mlx_new_window(env->mlx, RES_X, RES_Y, "FdF");
	env->img = mlx_new_image(env->mlx, RES_X, RES_Y);
	if (!env->img)
		mlx_close(env);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
		&env->line_length, &env->endian);
	if (!env->addr)
		mlx_close(env);
	update_wdw(env);
	mlx_hook(env->mlx_win, 2, 1L << 0, key_hook, env);
	mlx_hook(env->mlx_win, 17, 1L << 8, mlx_close, env);
	mlx_loop(env->mlx);
}

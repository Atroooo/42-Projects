/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:21:37 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/01 22:53:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	move_in_wdw(int keycode, t_env *env)
{
	if (keycode == Key_Down)
		env->current_y -= 50;
	else if (keycode == Key_Up)
		env->current_y += 50;
	else if (keycode == Key_Right)
		env->current_x -= 50;
	else if (keycode == Key_Left)
		env->current_x += 50;
	update_wdw(env);
}

void	zoom_in_wdw(int keycode, t_env *env)
{
	if (keycode == Key_Minus)
		env->zoom *= 0.95;
	else if (keycode == Key_Plus)
		env->zoom *= 1.05;
	update_wdw(env);
}

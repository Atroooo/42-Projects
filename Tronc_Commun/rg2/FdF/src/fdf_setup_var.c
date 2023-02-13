/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_setup_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:21:23 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/09 13:31:22 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static void	setup_scaling(t_env *env)
{
	if (env->index_x > 200)
	{
		env->mult = 1.5;
		env->scale = 1.0;
	}
	else if (env->index_x > 100 && env->index_x <= 200)
	{
		env->mult = 1.0;
		env->scale = 4.0;
	}
	else if (env->index_x >= 20 && env->index_x <= 100)
	{
		env->mult = 0.75;
		env->scale = 5.0;
	}
	else if (env->index_x < 20)
	{
		env->mult = 0.5;
		env->scale = 15.0;
	}
}

void	setup_var(t_env *env)
{
	env->current_x = 0;
	env->current_y = 0;
	env->zoom = 1;
	env->rotatex = 3.1415 / 48;
	env->rotatey = 0.0;
	env->rotatez = 0.0;
	env->idx_max = env->index_y * env->index_x;
	env->max_posx = 0;
	env->max_posy = 0;
	env->max_z = 0;
	env->proj = 0;
	setup_scaling(env);
}

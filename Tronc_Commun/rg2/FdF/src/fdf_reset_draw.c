/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reset_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:28:25 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/04 16:28:25 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	reset_wdw(t_env *env)
{
	int		index;

	index = 0;
	env->zoom = 1.0;
	env->rotatex = 3.1415 / 3.0;
	env->rotatey = -0.2;
	env->rotatez = -0.1;
	env->current_x = 0.0;
	env->current_y = 0.0;
	env->max_posx = 0.0;
	env->max_posy = 0.0;
	while (index < env->idx_max)
	{
		env->map[index]->x = env->map[index]->b_x;
		env->map[index]->y = env->map[index]->b_y;
		env->map[index]->z = env->map[index]->b_z;
		index++;
	}
	update_wdw(env);
}

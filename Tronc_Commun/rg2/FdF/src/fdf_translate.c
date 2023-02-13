/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:28:45 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/04 16:28:45 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	translate(t_env *env, int index)
{
	env->map[index]->x += -env->index_x / 2 + 0.5;
	env->map[index]->y += -env->index_y / 2 + 0.5;
	env->map[index]->z += -env->max_z / 2;
}

void	center(t_env *env, int index)
{
	env->map[index]->x += (env->index_x / 2);
	env->map[index]->y += (env->index_y / 2);
	env->map[index]->z += (env->max_z / 2);
}

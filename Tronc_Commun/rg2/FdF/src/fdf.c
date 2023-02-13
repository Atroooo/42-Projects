/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:24:28 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/13 14:59:16 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 1)
	{
		ft_printf("Usage : ./fdf testmaps/map.fdf");
		close(0);
		close(1);
		close(2);
		exit(0);
	}
	env = malloc(sizeof(t_env));
	setup_env(argc, argv, env);
	mlx_setup(env);
	mlx_destroy_display(env->mlx);
	return (0);
}

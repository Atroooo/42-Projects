/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:42:35 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/13 14:56:51 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static t_point	*create_point(t_env *env, int x, int y, int z)
{	
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		error(env);
	point->x = x;
	point->b_x = x;
	point->y = y;
	point->b_y = y;
	if (z < 0)
		point->z = z - 1;
	else
		point->z = z + 1;
	if (env->max_z < point->z)
		env->max_z = point->z;
	point->b_z = point->z;
	point->dx = 0;
	point->dy = 0;
	point->color = 0xFFFFFF;
	return (point);
}

static t_point	*setup_map(char *line, int x, int y, t_env *env)
{	
	t_point	*point;
	char	**value;
	int		i;
	int		z;

	value = ft_split(line, ',');
	z = z_value(value);
	point = create_point(env, x, y, z);
	if (value[1] != NULL)
	{
		i = 0;
		while (value[1][i])
		{
			if (value[1][1] == 'x')
				value[1][1] = '0';
			ft_toupper(value[1][i]);
			i++;
		}
		point->color = ft_atoi_base(value[1], "0123456789ABCDEF");
	}
	else
		point->color = 0xFFFFFF;
	free_split(value);
	return (point);
}

void	parse_file(int fd, t_env *env)
{
	char	**line;
	char	*str_file;
	int		y;
	int		x;

	init(&x, &y);
	str_file = get_next_line(fd);
	line = ft_split(str_file, ' ');
	while (y * env->index_x + x < env->idx_max)
	{
		if (x == env->index_x)
		{
			free_str(line, str_file);
			str_file = get_next_line(fd);
			line = ft_split(str_file, ' ');
			x = 0;
			y++;
		}
		if (!line[x])
			handle_err_par(env, line, str_file, fd);
		env->map[y * env->index_x + x] = setup_map(line[x], x, y, env);
		x++;
	}
	free_str(line, str_file);
	env->map[y * env->index_x + x] = NULL;
}

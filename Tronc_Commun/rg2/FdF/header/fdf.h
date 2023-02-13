/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:42:24 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/13 14:58:31 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//Minilibx
# include "../minilibx_linux/mlx.h"

//Libraries
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

# include <stdio.h>
//Functions
# include "../libft/header/libft.h"
# include "get_next_line.h"
# include "fdf_keys.h"

# define RES_X 1920
# define RES_Y 1080
# define INC_ROT 0.1
# define Z_NEAR 0.1
# define Z_FAR 10

typedef struct s_point
{
	int		color;
	double	b_x;
	double	b_y;
	double	b_z;
	double	x;
	double	y;
	double	z;
	double	w;
	double	posx;
	double	posy;
	double	dx;
	double	dy;
}	t_point;

typedef struct s_env
{
	t_point	**map;
	int		max_z;
	int		idx_max;
	int		index_x;
	int		index_y;
	double	current_x;
	double	current_y;
	double	zoom;
	double	max_posx;
	double	max_posy;
	double	rotatex;
	double	rotatey;
	double	rotatez;
	double	mult;
	double	scale;
	int		proj;

	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_env;

//Parsing file
void		setup_env(int argc, char **argv, t_env *env);
void		setup_var(t_env *env);
int			ft_atoi_base(char *str, char *base);
void		parse_file(int fd, t_env *env);

//Parsing utils
int			z_value(char **value);
void		free_str(char **line, char *str_file);
void		handle_err_par(t_env *env, char **line, char *str_file, int fd);
void		init(int *x, int *y);

//Display
void		mlx_setup(t_env *env);
void		reset_wdw(t_env *env);

//Draw
void		pixel_put(t_env *env, int index);
void		my_mlx_pixel_put(t_env *env, int x, int y, int color);
void		print_coords_proj(t_env *env);
void		print_coords_iso(t_env *env);
void		print_lines(t_env *env);

//Get coords
void		translate(t_env *env, int index);
void		center(t_env *env, int index);
void		rotate_coord(t_env *env, int index);
void		zoom(t_env *env, int index);

//Move 
void		update_wdw(t_env *env);
void		rotate(int keycode, t_env *env);
void		move_in_wdw(int keycode, t_env *env);
void		zoom_in_wdw(int keycode, t_env *env);

//Errors
void		clear_struct(t_env *env);
void		free_split(char **str);
void		error(t_env *env);
int			mlx_close(t_env *env);
void		error_parsing(t_env *env, int fd);

#endif
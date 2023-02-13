/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:56:21 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/13 14:57:04 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	z_value(char **value)
{
	if (!value)
		return (0);
	else
		return (ft_atoi(value[0]));
}

void	free_str(char **line, char *str_file)
{
	if (str_file)
		free(str_file);
	if (line)
		free_split(line);
}

void	handle_err_par(t_env *env, char **line, char *str_file, int fd)
{
	free_str(line, str_file);
	error_parsing(env, fd);
}

void	init(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

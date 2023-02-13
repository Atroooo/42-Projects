/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:39:43 by vgonnot           #+#    #+#             */
/*   Updated: 2022/07/25 19:41:23 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	number_col(char *str)
{
	int	i;
	int	col;

	i = 0;
	col = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			col++;
		i++;
	}
	return (col);
}

int	*set_array(int *i, int *k, int *col, char *str)
{
	int	*line;

	line = malloc(sizeof(int) * (*col));
	*col = 0;
	while (str[*i] == '.' || str[*i] == '\n' || str[*i] == 'o')
	{
		(*k)++;
		if (str[*i] == '\n')
		{
			line[*col] = *k;
			*k = 0;
			(*col)++;
			(*i)++;
		}
		(*i)++;
	}
	return (line);
}

int	check_error(t_treat_arr *array)
{
	char	*str;
	int		i;
	int		k;
	int		*line;
	int		col;

	str = array->treated_arr;
	i = 0;
	k = -1;
	col = number_col(str);
	line = set_array(&i, &k, &col, str);
	if (str[i -1] != '\0' || i < 3 || col < 1)
	{
		ft_putstr("map error\n");
		return (-1);
	}
	while (k + 1 < col)
	{
		if (line[k] != line[k +1])
		{
			ft_putstr("map error\n");
			return (-1);
		}
		k++;
	}
	if (line[0] != col)
	{
			ft_putstr("map error\n");
			return (-1);
	}
	return (0);
}

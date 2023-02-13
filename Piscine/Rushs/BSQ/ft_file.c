/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:15:46 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/25 15:49:34 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	length_file(char *file_name)
{
	int				file;
	int				index;
	int				i;
	char			buf[2];

	i = 0;
	index = 1;
	file = open(file_name, O_RDONLY);
	if (file == -1)
	{
		ft_putstr("File error\n");
		return (-1);
	}
	while (index)
	{
		index = read(file, buf, 1);
		buf[index] = '\0';
		i += 1;
	}
	if (close(file) == -1)
	{
		ft_putstr("File error\n");
		return (-1);
	}
	return (i);
}

t_filedata	*get_file_data(t_filedata *file_s)
{
	char		*buf;
	int			file;
	int			ret;

	buf = malloc(file_s->file_length + 1);
	buf[0] = 0;
	file = open(file_s->file_name, O_RDONLY);
	if (file == -1)
	{
		ft_putstr("File error\n");
		return (NULL);
	}
	ret = read(file, buf, file_s->file_length);
	buf[ret] = '\0';
	file_s->file_content = buf;
	if (close(file) == -1)
	{
		ft_putstr("File error\n");
		return (NULL);
	}
	return (file_s);
}

t_treat_arr	*fix_array(t_treat_arr *array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array->untouch_a[i] != '\n')
		i++;
	array->start_pos = i;
	while (array->untouch_a[i++])
	{
		array->treated_arr[j] = array->untouch_a[i];
		j++;
	}
	array->treated_arr[j] = '\0';
	return (array);
}

t_resolv	*parsed_str(t_treat_arr *array, t_resolv *resolv_s)
{
	int	i;

	i = 0;
	resolv_s->parsed_arr = ft_split(array->treated_arr, "\n");
	while (resolv_s->parsed_arr[i])
	{
		resolv_s->resolv_arr[i] = malloc(sizeof(char) * (ft_strlen(resolv_s->parsed_arr[i])));
		resolv_s->resolv_arr[i] = ft_strncpy(resolv_s->resolv_arr[i], resolv_s->parsed_arr[i], ft_strlen(resolv_s->parsed_arr[i]));
		i++;
	}
	resolv_s->resolv_arr[i] = NULL;
	return (resolv_s);
}
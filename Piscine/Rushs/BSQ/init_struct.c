/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:04:10 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/25 19:41:30 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

t_filedata	*init_file_struct(char *file_name)
{
	t_filedata	*file_d;

	file_d = malloc(sizeof(t_filedata));
	file_d->file_length = length_file(file_name);
	file_d->file_name = file_name;
	return (file_d);
}

t_treat_arr	*init_resol_arr_struct(t_filedata *file_d)
{
	t_treat_arr	*array;

	array = malloc(sizeof(t_treat_arr));
	array->untouch_a = file_d->file_content;
	array->treated_arr = malloc(ft_strlen(array->untouch_a));
	return (array);
}

t_resolv	*init_resolv_struct(t_treat_arr *array)
{
	t_resolv	*resolv_s;

	resolv_s = malloc(sizeof(t_resolv));
	resolv_s->resolv_arr = malloc(sizeof(char *));
	return (resolv_s);
}

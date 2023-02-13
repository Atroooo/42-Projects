/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:10:35 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/25 19:38:52 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include <stdio.h>

int	bsq_resolution(char *argv)
{
	t_filedata	*file_d;
	t_treat_arr	*array;
	t_resolv	*resolv_s;


	file_d = init_file_struct(argv);
	file_d = get_file_data(file_d);
	array = init_resol_arr_struct(file_d);
	array = fix_array(array);
	resolv_s = init_resolv_struct(array);
	resolv_s = parsed_str(array, resolv_s);
	
	if (check_error(array) == -1)
		return (-1);
	resolv_s = resolv_enigma(resolv_s);
	return (0);
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	while (i++ < argc)
	{
		bsq_resolution(argv[i]);
		i++;
	}
	return (0);
}

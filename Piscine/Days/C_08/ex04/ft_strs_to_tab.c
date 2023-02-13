/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 04:23:49 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/28 16:11:30 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*str_to_struct;

	if (ac <= 0)
		ac = 0;
	str_to_struct = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!str_to_struct)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		str_to_struct[i].str = av[i];
		str_to_struct[i].size = ft_strlen(av[i]);
		str_to_struct[i].copy = ft_strdup(str_to_struct[i].str);
		i++;
	}
	str_to_struct[i].str = 0;
	return (str_to_struct);
}

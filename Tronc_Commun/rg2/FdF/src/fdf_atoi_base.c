/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_atoi_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:15:11 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/04 16:27:44 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static int	getbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

static int	nb_inbase(int nbr, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if ((nbr) == (base[i] - '0'))
			return (1);
		i++;
	}
	return (0);
}

static int	calc_nbr(char c, int nb, char *base)
{
	int	length;
	int	nbtemp;
	int	i;

	length = getbase(base);
	nbtemp = nb;
	i = 0;
	while (i < length)
	{
		if (c == base[i])
			nbtemp = nbtemp * length + i;
		i++;
	}
	return (nbtemp);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nb;
	int	i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (nb_inbase((str[i] - '0'), base))
	{
		nb = calc_nbr(str[i], nb, base);
		i++;
	}
	return (sign * nb);
}

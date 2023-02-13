/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:07:51 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/28 18:27:35 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		getbase(char *base);
int		checkbase(char *base);
int		nb_inbase(int nbr, char *base);
char	*ft_rev_tab(char *tab);

char	*convert_nb_inbase(long int nbr, char *base)
{
	long int	length;
	int			i;
	char		*nb;

	length = getbase(base);
	nb = malloc(200000);
	if (nbr < 0 && checkbase(base) == 1)
	{
		nbr *= -1;
		i = 1;
		nb[0] = '-';
	}
	else
		i = 0;
	while (nbr > 0)
	{
		nb[i] = (nbr % length) + 48;
		nbr = nbr / length;
		i++;
	}
	return (nb);
}

int	calc_nbr(char c, int nb, char *base)
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
	if (checkbase(base) == 0)
		return (0);
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nbtemp;

	if (checkbase(base_from) == 0 || checkbase(base_to) == 0)
		return (0);
	else
	{
		nbtemp = ft_atoi_base(nbr, base_from);
		if (nbtemp == 0)
		{
			nbr = malloc(1);
			nbr[0] = '0';
			return (nbr);
		}
		nbr = malloc(sizeof(char) * getbase(nbr));
		nbr = convert_nb_inbase(nbtemp, base_to);
		nbr = ft_rev_tab(nbr);
	}
	return (nbr);
}

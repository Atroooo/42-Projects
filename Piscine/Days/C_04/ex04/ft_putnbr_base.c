/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:51:20 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/26 14:10:48 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	getbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == ' ' || base[i] == '\f'
				|| base[i] == '\n' || base[i] == '\r'
				|| base[i] == '\t' || base[i] == '\v'
				|| base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_putnbrbase_all(int nbr, char *base)
{
	long int	nbtemp;
	long int	length;

	nbtemp = nbr;
	length = getbase(base);
	if (nbtemp < 0 && checkbase(base) == 1)
	{
		ft_putchar('-');
		nbtemp *= -1;
	}
	if (nbtemp > 0)
	{
		ft_putnbrbase_all(nbtemp / length, base);
		ft_putchar(base[nbtemp % length]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nbtemp;

	nbtemp = nbr;
	if (checkbase(base) == 1 && nbr == 0 && getbase(base) > 0)
		ft_putchar(base[0]);
	else if (checkbase(base) == 1 && getbase(base) > 0)
		ft_putnbrbase_all(nbtemp, base);
}

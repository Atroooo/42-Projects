/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:40:01 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/18 22:22:07 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

int	nb_inbase(int nbr, char *base)
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

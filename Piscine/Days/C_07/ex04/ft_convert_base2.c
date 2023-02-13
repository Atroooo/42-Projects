/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:08:06 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/19 22:40:18 by lcompieg         ###   ########lyon.fr   */
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

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_rev_tab(char *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	while (j < i / 2)
	{
		if (tab[j] == '-')
		{
			j++;
			i++;
		}
		ft_swap(&tab[j], &tab[i - j - 1]);
		j++;
	}
	return (tab);
}

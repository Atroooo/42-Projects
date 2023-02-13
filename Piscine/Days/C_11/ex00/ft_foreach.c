/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:17:19 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/21 18:37:20 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    rec(long int nb_long)
{
	if (nb_long < 0)
	{
		write(1, "-", 1);
		nb_long *= -1;
	}
	if (nb_long > 0)
	{
		rec(nb_long / 10);
		ft_putchar(nb_long % 10 + '0');
	}
}

void    ft_putnbr(int nb)
{
	long int    nb_long ;

	nb_long = nb ;
	if (nb_long == 0)
		write(1, "0", 1);
	if (nb_long > 0)
		rec(nb_long);
}

void ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int main()
{
	void (*ptr)(int);

	ptr = &ft_putnbr;

	int int_tab[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	ft_foreach(int_tab, 20, ptr);
}

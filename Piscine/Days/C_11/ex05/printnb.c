/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:35:49 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/22 15:37:32 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_all(int nb)
{
	long int	nbtemp;

	nbtemp = nb;
	if (nbtemp < 0)
	{
		ft_putchar('-');
		nbtemp *= -1;
	}
	if (nbtemp > 0)
	{
		ft_putnbr_all(nbtemp / 10);
		ft_putchar(nbtemp % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar('0');
	else
		ft_putnbr_all(nb);
}

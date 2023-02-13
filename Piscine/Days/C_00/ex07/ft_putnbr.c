/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:31:59 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/08 10:32:03 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
	}
}

void	test_zero(int n)
{
	if (n == 0)
	{
		ft_putchar(48);
	}
}

void	ft_putnbr(int nb)
{
	long int	test_nb;
	int			nb_temp;

	nb_temp = nb;
	test_nb = 1;
	ft_is_negative(nb);
	if (nb < 0)
	{
		test_nb *= (-1);
	}
	while (nb_temp != 0)
	{
		nb_temp = nb / test_nb;
		test_nb = test_nb * 10;
	}
	test_nb = test_nb / 100;
	test_zero(nb);
	while (test_nb != 0)
	{
		nb_temp = nb / test_nb;
		ft_putchar(nb_temp + 48);
		nb = nb - nb_temp * test_nb;
		test_nb = test_nb / 10;
	}
}

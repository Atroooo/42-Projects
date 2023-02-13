/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:52:03 by lcompieg          #+#    #+#             */
/*   Updated: 2022/11/16 15:27:12 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long int nb, int fd)
{
	long int	nbtemp;

	nbtemp = nb;
	if (nbtemp < 0)
	{
		ft_putchar_fd('-', fd);
		nbtemp *= -1;
	}
	if (nbtemp > 0)
	{
		ft_putnbr(nbtemp / 10, fd);
		ft_putchar_fd(nbtemp % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(long int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		ft_putnbr(n, fd);
}

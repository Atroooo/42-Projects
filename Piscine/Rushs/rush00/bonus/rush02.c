/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 08:05:37 by mchenava          #+#    #+#             */
/*   Updated: 2022/07/09 11:07:54 by mchenava         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define CORNER_L 'A'
#define CORNER_R 'C'
#define SIDE 'B'

void	ft_putchar(char c);

void	longueur(int l, int h, int x, int y)
{
	if ((l == 1 && h == 1) || (l == x && h == 1))
		ft_putchar(CORNER_L);
	else if ((l == 1 && h == y) || (l == x && h == y))
		ft_putchar(CORNER_R);
	else
		ft_putchar(SIDE);
}

void	largeur(int l, int x)
{
	if (l == 1 || l == x)
		ft_putchar(SIDE);
	else
		ft_putchar(' ');
}

int	test_nu(int x, int y)
{
	if (x <= 0 || y <= 0)
		return (0);
	else
		return (1);
}

void	rush(int x, int y)
{
	int	h;
	int	l;

	if (test_nu (x, y) == 0)
	{
		write (1,
			"La fonction n'accepte que les entiers strictement positifs",
			58);
		return ;
	}
	h = 1;
	while (h < y + 1)
	{
		l = 1;
		while (l < x + 1)
		{
			if (h == 1 || h == y)
				longueur(l, h, x, y);
			else
				largeur(l, x);
			l++;
		}
		ft_putchar('\n');
		h++;
	}
}

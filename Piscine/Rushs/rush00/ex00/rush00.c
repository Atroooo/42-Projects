/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 08:05:37 by mchenava          #+#    #+#             */
/*   Updated: 2022/07/09 13:26:24 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define CORNER 'o'
#define VER_SIDE '|'
#define HOR_SIDE '-'

void	ft_putchar(char c);

void	longueur(int l, int x)
{
	if (l == 1 || l == x)
		ft_putchar(CORNER);
	else
		ft_putchar(HOR_SIDE);
}

void	largeur(int l, int x)
{
	if (l == 1 || l == x)
		ft_putchar(VER_SIDE);
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
				longueur(l, x);
			else
				largeur(l, x);
			l++;
		}
		ft_putchar('\n');
		h++;
	}
}

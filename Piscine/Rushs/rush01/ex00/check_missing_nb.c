/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_missing_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:28:22 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/17 21:34:01 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	missing_on_row(int nb, int tab[6][6], int x)
{
	int	y;

	y = 1;
	while (y < 5)
	{
		if (tab[x][y] == nb)
			return (0);
		y++;
	}
	return (1);
}

int	missing_on_col(int nb, int tab[6][6], int y)
{
	int	x;

	x = 1;
	while (x < 5)
	{
		if (tab[x][y] == nb)
			return (0);
		x++;
	}
	return (1);
}

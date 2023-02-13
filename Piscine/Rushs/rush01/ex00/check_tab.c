/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:09:07 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/17 21:33:51 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	missing_on_row(int nb, int tab[6][6], int x);
int	missing_on_col(int nb, int tab[6][6], int y);

int	check_col_up(int tab[6][6], int x)
{
	int	y;
	int	count;
	int	max;

	y = 1;
	count = 1;
	max = tab[x][y];
	while (y < 5)
	{
		if (max < tab[x][y + 1])
		{
			max = tab[x][y + 1];
			count++;
		}
		if (tab[x][y + 1] == 0)
			count = tab[x][0];
		y++;
	}
	if (count == tab[x][0])
		return (1);
	return (0);
}

int	check_col_down(int tab[6][6], int x)
{
	int	y;
	int	count;
	int	max;

	y = 4;
	count = 1;
	max = tab[x][y];
	while (y > 1)
	{
		if (max < tab[x][y - 1])
		{
			max = tab[x][y - 1];
			count++;
		}
		if (tab[x][y - 1] == 0)
			count = tab[x][5];
		y--;
	}
	if (count == tab[x][0])
		return (1);
	return (0);
}

int	check_line_left(int tab[6][6], int y)
{
	int	x;
	int	count;
	int	max;

	x = 1;
	count = 1;
	max = tab[x][y];
	while (x < 5)
	{
		if (max < tab[x + 1][y])
		{
			max = tab[x + 1][y];
			count++;
		}
		if (tab[x + 1][y] == 0)
			count = tab[0][y];
		x++;
	}
	if (count == tab[0][y])
		return (1);
	return (0);
}

int	check_line_right(int tab[6][6], int y)
{
	int	x;
	int	count;
	int	max;

	x = 4;
	count = 1;
	max = tab[x][y];
	while (x > 1)
	{
		if (max < tab[x - 1][y])
		{
			max = tab[x - 1][y];
			count++;
		}
		if (tab[x - 1][y] == 0)
			count = tab[5][y];
		x--;
	}
	if (count == tab[0][y])
		return (1);
	return (0);
}

int	is_valid(int tab[6][6], int x, int y)
{
	int	nb;

	nb = 1;
	if (x * y == 25)
		return (1);
	if (x == 5)
	{
		x = 1;
		y += 1;
	}
	if (tab[x][y] != 0)
		return (is_valid(tab, x + 1, y));
	while (nb < 5)
	{
		if ((missing_on_row(nb, tab, x) == 1 && missing_on_col(nb, tab, y) == 1)
			&& (check_col_up(tab, x) == 0 || check_col_down(tab, x) == 0)
			&& (check_line_left(tab, y) == 0 || check_line_right(tab, y) == 0))
		{
			tab[x][y] = nb;
			if (is_valid(tab, x + 1, y))
				return (1);
		}
		nb++;
	}
	return (0);
}

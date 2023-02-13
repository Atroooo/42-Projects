/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:34:33 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/17 21:52:13 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_valid(int tab[6][6], int x, int y);
void	ft_putchar(char c);

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_tab(int tab[6][6])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < 5)
	{
		while (j < 5)
		{
			ft_putchar(tab[i][j] + 48);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 1;
		i++;
	}
}

int	*fill_row(int tab[6][6], char **argv, int str_pos)
{
	int	j;
	int	k;

	j = 1;
	k = 0;
	while (argv[0][str_pos])
	{
		if (argv[0][str_pos + 1] == '\0')
			tab[4][5] = (int)argv[0][str_pos] - 48;
		if (argv[0][str_pos] == ' ' && j < 6)
		{
			tab[j][k] = (int)argv[0][str_pos - 1] - 48;
			j++;
		}
		else if (j == 5 && k == 0)
		{
			j = 1;
			k = 5;
		}
		str_pos++;
	}
	return (tab[6]);
}

int	*fill_col(int tab[6][6], char **argv)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	k = 1;
	l = 0;
	while (argv[0][l] && l < 16)
	{
		if (argv[0][l] == ' ' && k < 6)
		{
			tab[j][k] = (int)argv[0][l - 1] - 48;
			k++;
		}
		if (k == 5)
		{
			j = 5;
			k = 1;
		}
		l++;
	}
	fill_row(tab, argv, l);
	return (tab[6]);
}

void	setup_tab(char **argv)
{
	int	tab[6][6];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (j < 6)
		{
			tab[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	fill_col(tab, argv);
	is_valid(tab, 1, 1);
	print_tab(tab);
}

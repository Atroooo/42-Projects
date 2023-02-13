/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:51:43 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/17 21:35:00 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	setup_tab(char **argv);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	test_error(int i, char *clue, int nb_clue)
{
	while (i < nb_clue * 2)
	{
		if (clue[i] > '4' || clue[i] < '1')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else if (nb_clue != 16)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i = i + 2;
	}
	return (1);
}

int	count_clue(char *tab_clue)
{
	int	c;
	int	nb;

	c = 0;
	nb = 0;
	while (tab_clue[c])
	{
		if (tab_clue[c] != ' ' && c % 2 == 0)
			nb++;
		else if (tab_clue[c] != ' ')
		{
			nb = 0;
			break ;
		}
		c++;
	}
	if (c % 2 == 0)
		nb = 0;
	return (nb);
}

int	check(int argc, char **clue)
{
	int	i;
	int	nb_clue;

	i = 0;
	if (argc == 1 || argc > 2)
	{
		write(1, "Error\n", 6);
		i = 999999;
		return (0);
	}
	nb_clue = count_clue(clue[1]);
	if (test_error(i, clue[1], nb_clue) == 0)
		return (0);
	if (nb_clue == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (check(argc, argv) == 0)
		return (0);
	else
		setup_tab(&argv[1]);
	return (0);
}

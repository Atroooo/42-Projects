/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:44:57 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/28 06:43:12 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		y;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		y = i + 1;
		while (y < argc)
		{
			if (ft_strcmp(argv[i], argv[y]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[y];
				argv[y] = temp;
			}
			y++;
		}
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:25:35 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/22 15:39:57 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_purchar(char c);
void	ft_putnbr_all(int nb);
void	ft_putnbr(int nb);

int	check_sign(char c)
{
	int	i;

	i = 0;
	if (c == '+' || c == '-' || c == '/' || c == '%' || c == '*')
		return (1);
	return (0);
}

int	error_calc(int nb, char c)
{
	if (nb == 0)
	{
		if (c == '/')
		{
			write(1, "Stop : division by zero", 24);
			return (0);
		}
		else if (c == '%')
		{
			write(1, "Stop : modulo by zero", 23);
			return (0);
		}
	}
	return (1);
}

int	calc(int nb1, char c, int nb2)
{
	if (c == '+')
		return (nb1 + nb2);
	if (c == '-')
		return (nb1 - nb2);
	if (c == '/')
		return (nb1 / nb2);
	if (c == '%')
		return (nb1 % nb2);
	if (c == '*')
		return (nb1 * nb2);
	return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nb;
	int	i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (48 <= str[i] && str[i] <= 57)
	{
		nb = (nb * 10) + str[i] - '0';
		if (!(48 <= str[i + 1] && str[i + 1] <= 57))
			return (sign * nb);
		i++;
	}
	return (0);
}

int	doop(char *str1, char s, char *str2, int (*f)(int, char, int))
{
	int	nb;
	int	nb2;

	nb = ft_atoi(str1);
	nb2 = ft_atoi(str2);
	if (check_sign(s) == 0 || error_calc(nb2, s) == 0)
		return (0);
	ft_putnbr((f(nb, s, nb2)));
	return (1);
}

int main(int argc, char **argv)
{
	int	(*ptr)(int, char, int);

	ptr = &calc;
	if (argc > 5)
		return (0);
	else
		doop(argv[1], *argv[2], argv[3], ptr);
}

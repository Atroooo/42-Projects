/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:57:31 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/15 13:47:16 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_dec_hex(char c)
{
	int	digit;

	write(1, "\\", 1);
	digit = (c >> 4) & 0xf;
	if (digit >= 10)
		digit = digit - 10 + 'a';
	else
		digit += '0' ;
	write(1, &digit, 1);
	digit = c & 0xf;
	if (digit >= 10)
		digit = digit - 10 + 'a';
	else
		digit += '0' ;
	write(1, &digit, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 31)
			convert_dec_hex(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

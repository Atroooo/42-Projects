/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:11:01 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/16 14:51:51 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	convert_to_hexa(unsigned char c)
{
	unsigned char	a;
	unsigned char	b;

	a = c >> 4;
	b = c & 0xf;
	ft_putchar("0123456789abcdef"[a]);
	ft_putchar("0123456789abcdef"[b]);
}

void	addr_first_to_hexa(char *c)
{
	int					digit;
	int					i;
	unsigned long long	c_value;

	c_value = (unsigned long long)c;
	i = 7;
	while (i > -1)
	{
		digit = (c_value >> i * 8) & 0xff;
		convert_to_hexa(digit);
		i--;
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	ft_print_hexa(char *addr, unsigned int start_pos, unsigned int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 16 && i + start_pos < size)
	{
		convert_to_hexa(addr[i + start_pos]);
		i++;
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
	if (i + start_pos == size)
		write(1, "     ", 5);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;
	char			*addr_array;

	i = 0;
	addr_array = addr;
	while ((addr + i * 16) && i * 16 < size)
	{
		if ((i + 1) * 16 > size + 16)
			return (0);
		addr_first_to_hexa(&addr_array[i + 16]);
		ft_print_hexa(&addr_array[i], i * 16, size);
		j = 0;
		while ((i * 16) + j < size && j < 16)
		{
			if (!(31 < addr_array[i * 16 + j] && addr_array[i * 16 + j] <= '~'))
				ft_putchar('.');
			else
				ft_putchar(addr_array[i * 16 + j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (addr);
}

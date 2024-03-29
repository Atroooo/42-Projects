/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:07:24 by lcompieg          #+#    #+#             */
/*   Updated: 2022/11/08 12:56:14 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*str;

	i = 0;
	str = b;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	b = str;
	return (b);
}

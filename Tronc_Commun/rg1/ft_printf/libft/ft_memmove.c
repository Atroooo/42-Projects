/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:50:21 by lcompieg          #+#    #+#             */
/*   Updated: 2022/11/15 12:48:43 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	index;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (src < dst && (size_t)(dst - src) < len)
	{
		index = len;
		while (index-- > 0)
			((char *) dst)[index] = ((char *) src)[index];
		return (dst);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

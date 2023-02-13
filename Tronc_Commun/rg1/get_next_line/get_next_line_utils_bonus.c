/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:26:27 by lcompieg          #+#    #+#             */
/*   Updated: 2022/11/29 14:10:14 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	index;

	index = 0;
	while (s && s[index])
		index++;
	return (index);
}

char	*ft_strnjoin(char *old_dst, char *src, size_t len)
{
	char	*dst;
	size_t	index;
	size_t	j;

	if (src == NULL)
		return (free(old_dst), NULL);
	dst = malloc(sizeof(char) * (ft_strlen(old_dst) + ft_strlen(src) + 1));
	if (!dst)
		return (free(old_dst), NULL);
	index = 0;
	j = 0;
	while (old_dst && old_dst[index])
	{
		dst[index] = old_dst[index];
		index++;
	}
	while (src[j] && j < len)
	{
		dst[index] = src[j];
		j++;
		index++;
	}
	dst[index] = '\0';
	return (free(old_dst), dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

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
	{
		index = 0;
		while (index < len)
		{
			((char *)dst)[index] = ((char *)src)[index];
			index++;
		}
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*str;

	i = 0;
	str = b;
	while (i < n && str[i])
	{
		str[i] = (char)c;
		i++;
	}
	b = str;
	return (b);
}

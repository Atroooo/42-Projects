/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:26:29 by lcompieg          #+#    #+#             */
/*   Updated: 2023/01/19 14:34:07 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

static int	get_index(char *buffer)
{
	int	index;

	if (!buffer)
		return (0);
	index = 0;
	while (buffer[index])
	{			
		if (buffer[index] == '\n')
			return (index);
		index++;
	}
	return (BUFFER_SIZE);
}

static char	*return_dst(char *buffer, char *dst)
{
	dst = ft_strnjoin(dst, buffer, get_index(buffer) + 1);
	ft_memmove(buffer, buffer + get_index(buffer) + 1, \
		BUFFER_SIZE - get_index(buffer));
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*dst;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	dst = NULL;
	if (buffer[0] != '\0')
	{
		if (get_index(buffer) != BUFFER_SIZE)
			return (return_dst(buffer, dst));
		dst = ft_strnjoin(dst, buffer, BUFFER_SIZE);
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (ft_memset(buffer, 0, BUFFER_SIZE), free(dst), NULL);
	while (bytes)
	{
		buffer[bytes] = '\0';
		if (get_index(buffer) != BUFFER_SIZE)
			return (return_dst(buffer, dst));
		dst = ft_strnjoin(dst, buffer, BUFFER_SIZE);
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_memset(buffer, 0, BUFFER_SIZE), dst);
}

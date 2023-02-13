/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:22:42 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/28 18:59:55 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int b1, unsigned int b2)
{
	unsigned int	len_src;
	unsigned int	i;
	unsigned int	l;

	len_src = b1;
	i = 0;
	l = 0;
	while (src[len_src] && len_src < b2)
	{
		dest[i] = src[len_src];
		len_src++;
		i++;
	}
	dest[len_src] = '\0';
	return (dest);
}

int	check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_charset(str[i], charset))
		{
			str[i] = '\0';
			i = 0;
		}
		i++;
	}
	if (ft_strlen(str) == 0)
		return (0);
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_split;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	str_split = malloc(sizeof(char *) * ft_strlen(str));
	while (str[i] + 1 != '\0')
	{
		if (check_charset(str[i], charset) || str[i + 1] == '\0')
		{
			str_split[j] = malloc(sizeof(char) * ft_strlen(str));
			ft_strncat(str_split[j], str, k + 1, i + 1);
			if (check_word(str_split[j], charset))
				j++;
			k = i;
		}
		i++;
	}
	str_split[j] = NULL;
	return (str_split);
}

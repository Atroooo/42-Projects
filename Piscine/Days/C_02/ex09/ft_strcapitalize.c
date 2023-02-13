/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:08:25 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/14 21:08:27 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	charactere(char c)
{
	if (!((65 <= c && c <= 90)
			|| (97 <= c && c <= 122)
			|| (48 <= c && c <= 57)))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word;

	word = 1;
	i = 0;
	while (str[i])
	{
		if (('A' <= str[i] && str[i] <= 'Z') && word == 1)
			word = 0;
		else if (('0' <= str[i] && str[i] <= '9') && word == 1)
			word = 0;
		else if (('A' <= str[i] && str[i] <= 'Z') && word == 0)
			str[i] = str[i] + 32;
		else if (('a' <= str[i] && str[i] <= 'z') && word == 1)
		{
			word = 0;
			str[i] = str[i] - 32 ;
		}
		else
			word = charactere(str[i]);
		i++;
	}
	return (str);
}

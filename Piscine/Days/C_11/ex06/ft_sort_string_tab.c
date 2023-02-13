/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:40:39 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/25 20:56:04 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void ft_sort_string_tab(char **tab)
{
	int	i;
	int j;

	i = 0;
	j = 1;
	while (tab[i])
	{
		while (tab[j])
		{
			if (strcmp(tab[i], tab[j] > 0)
				ft_swap(tab[i], tab[j]);
			j++;
		}
		i++;
		j = i + 1;
	}
	tab[i + 1] = '\0';
}


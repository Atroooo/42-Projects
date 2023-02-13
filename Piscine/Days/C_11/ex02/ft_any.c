/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:41:39 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/21 18:45:43 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_any(char **tab, int(*f)(char*))
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int    ft_str_is_lowercase(char *str)
{
	int    i ;

	i = 0;
	while (str[i])
	{
		if (97 <= str[i] && str[i] <= 122)
			i++;
		else
			return (0);
	}
	return (1);
}

int    main()
{
	int        (*ptr)(char *);
	char    **tab;
	char    *str1 = "JUSTEuNEMINUSCULE";
	char    *str2 = "justeUnemajuscule";
	char    *str3 = "TOUTENMAJUSCULE";
	char    *str4 = "toutenminuscule";
	char    *str5 = 0;

	tab = malloc(sizeof(char*) * 5);
	tab[0] = str1;
	tab[1] = str2;
	tab[2] = str3;
	tab[3] = str4;
	tab[4] = str5;
	ptr = &ft_str_is_lowercase;
	printf("%d \n",ft_any(tab, ptr));
	printf("%d \n",ft_str_is_lowercase(str1));
	printf("%d \n",ft_str_is_lowercase(str2));
	printf("%d \n",ft_str_is_lowercase(str3));
	printf("%d \n",ft_str_is_lowercase(str4));
}


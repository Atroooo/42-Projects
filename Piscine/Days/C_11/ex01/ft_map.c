/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:37:42 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/21 18:41:31 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int    ft_putchar(int c)
{
    return (c * 10);
}

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int *tab_r;
	int	i;

	tab_r = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		tab_r[i] = f(tab[i]);
		i++;
	}
	return (tab_r);
}

int    main()
{
    int    (*ptr)(int);
    int     index;
    int     lengh = 20;

    ptr = &ft_putchar;
    int int_tab[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int *new_tab = ft_map(int_tab, lengh, ptr);
    index = 0;
    while (index < lengh)
    {
        printf("%d \n",new_tab[index]);
        index++;
    }


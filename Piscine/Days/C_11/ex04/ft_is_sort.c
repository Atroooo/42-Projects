/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:51:19 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/22 14:22:54 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;
	int j;

	i = 0;
	if (f(tab[0], tab[length - 1]) > 0)
	{
		while (i < length - 1)
		{	
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
			i++;
		}
	}
	if (f(tab[0], tab[length - 1]) < 0)
	{
		while (i < length - 1)
		{	
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return 1;
}

int comp(int a, int b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	if (a == b)
		return (0);
	return (0);
}

int    ft_putchar(int c)
{
	return (c * 10);
}

int    main()
{
	int    (*ptr)(int,int);
	int     length = 5;

	ptr = &comp;
	//int int_tab[20] = {1,2,3,4,5};
	//int int_tab[20] = {5,4,3,2,1};
	int int_tab[20] = {5,4,6,2,1};
	printf("%d",ft_is_sort(int_tab, length, ptr));
}

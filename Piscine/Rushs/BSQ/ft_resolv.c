/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:13:13 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/25 16:29:49 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include <stdio.h>

void affichage(char **str)
{
    int i = 0;
    while (str[i])
    {
        printf("%s\n", str[i]);
        i++;
    }
    printf("\n");
}

t_resolv *resolv_enigma(t_resolv *resolv_s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (resolv_s->parsed_arr[i])
    {
        while (resolv_s->parsed_arr[i][j])
        {
            resolv_s->y = j;
            while(resolv_s->parsed_arr[i][j] != 'o' && resolv_s->parsed_arr[i][j])
            {
                resolv_s->x = i;
                resolv_s->resolv_arr[i][j] = 'x';
                if (resolv_s->resolv_arr[i][j + 1] == 'o')
                {
                    printf("%d\n", j);
                    affichage(resolv_s->resolv_arr);
                    resolv_s = check_square(resolv_s, j + 1, i);
                    return (resolv_s);
                }
                j++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (resolv_s);
}

t_resolv    *check_square(t_resolv *resolv_s, int j, int i)
{
    resolv_s = check_bottom(resolv_s, j, i);
    return (resolv_s);
}

t_resolv    *check_bottom(t_resolv *resolv_s, int j, int i)
{
    printf("%d, %d, %d\n", j, resolv_s->y, i);
    while (i < j - resolv_s->y && resolv_s->parsed_arr[i][j + 1] != '\0')
    {
        if (resolv_s->parsed_arr[i + 1][j] == 'o' && i + 1 < j - resolv_s->y)
        {
            resolv_s->resolv_arr = resolv_s->parsed_arr;
            return (resolv_s);
        }
        affichage(resolv_s->resolv_arr);
        resolv_s->resolv_arr[i][j] = 'x';
        i++;
    }
    resolv_s->x1 = i;
    resolv_s->y1 = j;
        
    resolv_s = check_backward(resolv_s, j, i);
    return (resolv_s); 
}

t_resolv    *check_backward(t_resolv *resolv_s, int j, int i)
{
    affichage(resolv_s->resolv_arr);
    while (j > resolv_s->y && resolv_s->parsed_arr[i][j] != 'o')
    {
        if (resolv_s->parsed_arr[i][j] == 'o' && j > resolv_s->y)
        {
            resolv_s->resolv_arr = resolv_s->parsed_arr;
            return (resolv_s);
        }
        resolv_s->resolv_arr[i][j] = 'x';
        j--;
    }
    resolv_s = check_upward(resolv_s, j, i);
    return (resolv_s); 
}

t_resolv    *check_upward(t_resolv *resolv_s, int j, int i)
{
    while (i > resolv_s->x && resolv_s->parsed_arr[i][j] != 'o')
    {
        if (resolv_s->parsed_arr[i][j] == 'o' && i > resolv_s->x)
        {
            resolv_s->resolv_arr = resolv_s->parsed_arr;
            return (resolv_s);
        }
        resolv_s->resolv_arr[i][j] = 'x';
        i--;
    }
    resolv_s = check_center(resolv_s, j, i);
    return (resolv_s);
}

t_resolv    *check_center(t_resolv *resolv_s, int j, int i)
{
    while (i != resolv_s->x1)
    {
        while (j != resolv_s->y1 && resolv_s->parsed_arr[i][j] != 'o')
        {
            if (resolv_s->parsed_arr[i][j] == 'o')
            {
                resolv_s->resolv_arr = resolv_s->parsed_arr;
                return (resolv_s);
            }
            resolv_s->resolv_arr[i][j] = 'x';
            j++;
        }
        j = resolv_s->x;
        i++;
    }
    return (resolv_s);
}
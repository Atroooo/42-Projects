/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:24:35 by lcompieg          #+#    #+#             */
/*   Updated: 2022/07/28 05:33:18 by lcompieg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	fibo_loop(int n)
{
	if (n < 2)
		return (n);
	else
		return (fibo_loop(n - 1) + fibo_loop(n - 2));
}

int	ft_fibonacci(int index)
{
	if (index >= 0)
		return (fibo_loop(index));
	return (-1);
}

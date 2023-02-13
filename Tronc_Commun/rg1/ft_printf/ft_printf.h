/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:01:15 by lcompieg          #+#    #+#             */
/*   Updated: 2022/11/18 18:22:28 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printf_str(char c, char *str);
int	ft_printf_char(char c, int nb);
int	ft_printf_nbr(char c, int nb);
int	ft_printf_addr(char c, unsigned long nb);
int	get_nbsize_hexa(unsigned long nb);

#endif
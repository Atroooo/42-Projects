/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:46:23 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/21 13:59:45 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_error(int i, t_stack *stack, char **str)
{
	free_split(str);
	if (i == 1)
		print_error(stack, 0);
	if (i < 2 || !check_stack(stack))
		print_error(stack, 1);
}

static t_stack	*fill_stack_nostr(t_stack *stack, char **argv, int argc)
{
	int	i;
	int	j;

	if (argc < 3)
		print_error(stack, 1);
	i = 1;
	while (i < argc && argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (((argv[i][j] == '-' || argv[i][j] == '+')
				&& !ft_isdigit(argv[i][j + 1])) || ((argv[i][j] != '-'
				&& argv[i][j] != '+') && !ft_isdigit(argv[i][j])))
				print_error(stack, 1);
			j++;
		}
		ft_add_backstack(&stack, ft_newstack(ft_atoi_s(argv[i], stack, NULL)));
		i++;
	}
	if (!check_stack(stack))
		print_error(stack, 1);
	return (stack);
}

static t_stack	*fill_stack_str(t_stack *stack, const char *argv)
{
	char	**str;
	int		i;
	int		j;

	str = ft_split(argv, ' ');
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (((str[i][j] == '-' || str[i][j] == '+')
				&& !ft_isdigit(str[i][j + 1])) || ((str[i][j] != '-'
				&& str[i][j] != '+') && !ft_isdigit(str[i][j])))
			{
				free_split(str);
				print_error(stack, 1);
			}
			j++;
		}
		ft_add_backstack(&stack, ft_newstack(ft_atoi_s(str[i], stack, str)));
		i++;
	}
	handle_error(i, stack, str);
	return (stack);
}

t_stack	*fill_stack(t_stack *stack, char **argv, int argc)
{
	if (argc < 2)
		print_error(stack, 1);
	else if (argc == 2)
		return (fill_stack_str(stack, argv[1]));
	else
		return (fill_stack_nostr(stack, argv, argc));
	return (NULL);
}

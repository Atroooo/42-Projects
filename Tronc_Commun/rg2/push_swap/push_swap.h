/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:32:12 by atro              #+#    #+#             */
/*   Updated: 2023/02/21 14:00:08 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h" 
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack{
	int				value;
	struct s_stack	*next;
}	t_stack;

//Sorting functions
void	ft_swap(t_stack **stack, char c);
void	ft_push(t_stack **stack_from, t_stack **stack_to, char c);
void	ft_rotate(t_stack **stack, char c);
void	ft_rrotate(t_stack **stack, char c);
void	ft_doubleswap(t_stack **stack_a, t_stack **stack_b);
void	ft_doublerotate(t_stack **stack_a, t_stack **stack_b);
void	ft_doublerrotate(t_stack **stack_a, t_stack **stack_b);

//Setup functions
t_stack	*ft_newstack(int value);
t_stack	*ft_laststack(t_stack *stack, int sw);
t_stack	*get_first_stack(t_stack *stack);
void	ft_add_frontstack(t_stack **stack, t_stack *new);
void	ft_add_backstack(t_stack **stack, t_stack *new);
int		ft_sizestack(t_stack *stack);
int		ft_atoi_s(const char *str, t_stack *stack, char **split);
t_stack	*fill_stack(t_stack *stack, char **argv, int argc);

//Error management functions
void	ft_clearstack(t_stack **stack);
void	print_error(t_stack *stack, int s);
int		check_stack(t_stack *stack);
int		stack_is_sort(t_stack *stack);
void	free_split(char **str);

//Sorting functions
int		get_min_value(t_stack *stack_a);
int		get_max_value(t_stack *stack_a);
int		get_second_max(t_stack *stack_a);
void	sort_action_one(t_stack **stack, char c);
void	sort_action_two(t_stack **stack, char c);
void	hard_sort_three_elem(t_stack **stack, char c);
void	hard_sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack, t_stack **stack_b, t_stack **temp_stack);
int		fd_idx(int value_to_find, t_stack *sorted_stack);
char	*cvt_binary(int number);

#endif
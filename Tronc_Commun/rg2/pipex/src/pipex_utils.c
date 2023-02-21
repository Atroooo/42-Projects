/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:21:41 by marvin            #+#    #+#             */
/*   Updated: 2023/02/16 13:21:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	free_str(char **str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
}

int	args_nempty(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (ft_isalpha(str[index]))
			return (1);
		index++;
	}
	return (0);
}

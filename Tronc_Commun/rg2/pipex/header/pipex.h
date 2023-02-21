/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:18:55 by marvin            #+#    #+#             */
/*   Updated: 2023/02/15 22:18:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>

# include <stdio.h>

# include "../libft/header/libft.h"
# include "get_next_line.h"

/*Execution functions*/
void	parent(char **argv, char **env, int *p_fd);
void	child(char **argv, char **env, int *p_fd);

/*Parsing functions*/
int	    args_nempty(char *str);

/*Free functions*/
void	free_str(char **tab);

#endif
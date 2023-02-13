/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:09:41 by lcompieg          #+#    #+#             */
/*   Updated: 2023/02/11 15:30:36 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

static int	check_filename(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	int				j;

	if (haystack == NULL && len == 0)
		return (0);
	i = 0;
	if (needle[i] == '\0')
		return (0);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0'
			&& i + j < len)
			j++;
		if (needle[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	count_word(char *str)
{
	char	**str_words;
	int		index;
	int		j;

	str_words = ft_split(str, ' ');
	index = 0;
	while (str_words[index])
		index++;
	j = 0;
	while (str_words[index - 1][j])
	{
		if (str_words[index - 1][j] != '\n')
			break ;
		else if (str_words[index - 1][j] == '\n')
		{
			index--;
			break ;
		}
		j++;
	}
	free_split(str_words);
	return (index);
}

static void	malloc_env(char *argv, t_env *env)
{
	char	*str;
	int		count_y;
	int		count_x;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error(env);
	count_y = 0;
	count_x = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (count_word(str) > count_x)
			count_x = count_word(str);
		free(str);
		str = get_next_line(fd);
		count_y++;
	}
	close(fd);
	env->map = malloc(sizeof(t_point *) * (count_y * count_x + 1));
	if (!(env->map))
		error(env);
	env->index_y = count_y;
	env->index_x = count_x;
}

void	setup_env(int argc, char **argv, t_env *env)
{
	int	fd;

	if (argc == 2)
	{
		if (check_filename(argv[1], ".fdf", ft_strlen(argv[1])))
		{
			malloc_env(argv[1], env);
			fd = open(argv[1], O_RDONLY);
			if (fd == -1)
				error(env);
			if (env->index_y == 0 || env->index_x == 0)
			{
				clear_struct(env);
				exit(0);
			}
			setup_var(env);
			parse_file(fd, env);
			close(fd);
		}
		else
			error(env);
	}
	else
		error(env);
}
